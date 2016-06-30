/*************************************************
Copyright:
Author:Barmaco
Qq:992077171
Date:2016-03-21
Description:
**************************************************/
#include "BaseNetDelegate.h"
#include <string.h>

namespace extension
{

BaseNetDelegate::BaseNetDelegate()
: m_nclientst(0)
{
}

BaseNetDelegate::~BaseNetDelegate()
{
	pthread_mutex_lock(&m_lSendBuffersMutex);
	while (!m_lSendBuffers.empty())
	{
		delete[] m_lSendBuffers.front().pBuffer;
		m_lSendBuffers.pop_front();
	}
	pthread_mutex_unlock(&m_lSendBuffersMutex);
}

int BaseNetDelegate::initsocket()
{
#if (TARGET_PLATFORM == TARGET_PLATFORM_WIN)
	// ����socket��̬���ӿ�(dll)
	WORD wVersionRequested;
	WSADATA wsaData;	// ��ṹ�����ڽ���Wjndows Socket�Ľṹ��Ϣ��
	int err;

	wVersionRequested = MAKEWORD(1, 1);	// ����1.1�汾��WinSock��

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return -1;			// ����ֵΪ���ʱ���Ǳ�ʾ�ɹ�����WSAStartup
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
		// ���������ֽ��ǲ���1�����ֽ��ǲ���1��ȷ���Ƿ������������1.1�汾
		// ����Ļ�������WSACleanup()�����Ϣ��������
		WSACleanup();
		return -1;
	}
#endif
	return 0;
}

SOCKET BaseNetDelegate::socket_connect(const char* hostname, int port)
{
	if (initsocket() == -1)
	{
		return 0;
	}

	SOCKET st = socket(AF_INET, SOCK_STREAM, 0);

	if (st == 0)
	{
		return 0;
	}

	struct sockaddr_in addr;					//����һ��IP��ַ�Ľṹ
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;					//���ýṹ��ַ����ΪTCP/IP��ַ
	addr.sin_port = htons(port);				//ָ��һ���˿ںţ�8080��htons:��short���ʹ�host�ֽ����͵�net�ֽ�����ת��
	addr.sin_addr.s_addr = inet_addr(hostname);	//���ַ����͵�IP��ַת��Ϊint������addr�ṹ��Ա.

	//����connect���ӵ��ṹaddrָ����IP��ַ�Ͷ˿ں�
	if (connect(st, (struct sockaddr *) &addr, sizeof(addr)) == -1)
	{
		printf("connect failed %s\n", strerror(errno));
		return 0;
	}

	return st;
}

SOCKET BaseNetDelegate::socket_create(int port)
{
	if (initsocket() == -1)
	{
		return 0;
	}

	SOCKET st = socket(AF_INET, SOCK_STREAM, 0);

	if (st == 0)
	{
		return 0;
	}

#if (TARGET_PLATFORM == TARGET_PLATFORM_WIN)
	const char on = 0;
#else
	int on = 0;
#endif

	if (setsockopt(st, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
	{
		printf("setsockopt failed %s\n", strerror(errno));
		return 0;
	}

	struct sockaddr_in addr;					//����һ��IP��ַ�ṹ
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;					//��addr�ṹ�����Զ�λΪTCP/IP��ַ
	addr.sin_port = htons(port);				//�������ֽ�˳��ת��Ϊ�����ֽ�˳��
	addr.sin_addr.s_addr = htonl(INADDR_ANY);	//INADDR_ANY������server�����еĵ�ַ

	//��IP��server�����
	if (bind(st, (struct sockaddr *) &addr, sizeof(addr)) == -1)
	{
		printf("bind failed %s\n", strerror(errno));
		return 0;
	}

	//server�˿�ʼlisten��
	if (listen(st, 20) == -1)
	{
		printf("listen failed %s\n", strerror(errno));
		return 0;
	}

	printf("listen %d success\n", port);

	return st;
}

SOCKET BaseNetDelegate::socket_accept(SOCKET listen_st)
{
	SOCKET client_st = 0;					//client��socket
	struct sockaddr_in client_addr;		//��ʾclient�˵�IP��ַ
	memset(&client_addr, 0, sizeof(client_addr));

#if (TARGET_PLATFORM == TARGET_PLATFORM_WIN)
	int len = 0;
#else
	unsigned int len = 1;
#endif
	len = sizeof(client_addr);

	//accept������ֱ���пͻ������ӹ�����accept����client��socket������
	client_st = accept(listen_st, (struct sockaddr *)&client_addr, &len);
	if (client_st == -1)
	{
		printf("accept failed %s\n", strerror(errno));
		return 0;
	}

	printf("accept by %s\n", inet_ntoa(client_addr.sin_addr));
	return client_st;
}

void BaseNetDelegate::sendm(SOCKET st, char* pBuffer, unsigned int uLen)
{
	if (!pBuffer || uLen == 0)
		return;

	Buffer pBuf;
	pBuf.writeData(pBuffer, uLen);
	sendm(st, pBuf);
}

void BaseNetDelegate::sendm(SOCKET st, Buffer& pBuffer)
{
	if (pBuffer.empty())
		return;

	unsigned int u_len = pBuffer.getContentSize();
	pBuffer.moveRight(sizeof(unsigned int));
	pBuffer.moveWriterIndexToFront();
	pBuffer.writeUInt(u_len);

	pBuffer.moveReaderIndexToFront();
	char* pData = pBuffer.readWholeData();	//��Ҫdelete
	int nLength = (int)pBuffer.getContentSize();
	pBuffer.moveReaderIndexToFront();

	SENDBUFFER tBuf;
	tBuf.pBuffer = pData;
	tBuf.nLength = nLength;
	tBuf.nOffset = 0;
	tBuf.st = st;

	pthread_mutex_lock(&m_lSendBuffersMutex);
	m_lSendBuffers.push_back(tBuf);
	pthread_cond_signal(&m_lSendBuffersCond);
	pthread_mutex_unlock(&m_lSendBuffersMutex);
}

void BaseNetDelegate::sendm(char* pBuffer, unsigned int uLen)
{
	sendm(m_nclientst, pBuffer, uLen);
}

void BaseNetDelegate::sendm(Buffer& pBuffer)
{
	sendm(m_nclientst, pBuffer);
}

void* BaseNetDelegate::runsendthread(void *context)
{
	BaseNetDelegate* obj = (BaseNetDelegate*)(context);
	obj->sendthread();
	return NULL;
}

void BaseNetDelegate::sendthread()
{
	while (true)
	{
		pthread_mutex_lock(&m_lSendBuffersMutex);
		/*
		��Ҫע���һ������thread4��ʹ�õ�while (iCount < 100),
		����if (iCount < 100)��
		������Ϊ��pthread_cond_singal()��pthread_cond_wait()����֮����ʱ��
		������ʱ����ڣ�thread3�ֽ�iCount������100�����ˣ�
		��ôthread4����Ҫ�ڵȴ�����Ϊ���ˡ�
		*/
		while (m_lSendBuffers.empty())
		{
			pthread_cond_wait(&m_lSendBuffersCond, &m_lSendBuffersMutex);
		}
		SENDBUFFER& tBuffer = m_lSendBuffers.front();

		int nRet = send(tBuffer.st, tBuffer.pBuffer + tBuffer.nOffset, tBuffer.nLength - tBuffer.nOffset, 0);

		if (nRet == -1)
		{
			break;
		}
		else if (nRet == tBuffer.nLength - tBuffer.nOffset)
		{
			delete[] tBuffer.pBuffer;
			m_lSendBuffers.pop_front();
		}
		else
		{
			tBuffer.nOffset += nRet;
		}

		pthread_mutex_unlock(&m_lSendBuffersMutex);
	}
}

void* BaseNetDelegate::runrecvthread(void *context)
{
	struct ps *psobj = (struct ps *)context;

	BaseNetDelegate *obj = (BaseNetDelegate *)psobj->obj;
	obj->recvthread(psobj->st);
	return NULL;
}

void BaseNetDelegate::recvthread(SOCKET st)
{
	char readbuf[SOCKET_READ_BUFFER_SIZE];
	extension::Buffer databuf;

	while (1)
	{
		memset(readbuf, 0, sizeof(readbuf));
		int rc = recv(st, readbuf, sizeof(readbuf), 0);
		if (rc <= 0)
			break;

		databuf.writeData(readbuf, (unsigned int)rc);

		//�����ݰ�
		while (databuf.isReadable(HEAD_SIZE))
		{
			int n_head_len = databuf.readInt();
			if (n_head_len <= 0)
			{
				databuf.moveLeft(sizeof(int));
				printf("invalidate head length");
				break;
			}

			int contentlen = databuf.getContentSize();

			if (contentlen - sizeof(int) >= n_head_len)
			{
				databuf.moveLeft(sizeof(int));
				Buffer pData;
				databuf.readData(&pData, n_head_len);
				databuf.moveLeft(n_head_len);
				databuf.moveReaderIndexToFront();
				databuf.moveWriterIndexToBack();

				onMessageReceived(st, pData);
			}
			else
			{
				databuf.moveReaderIndexToFront();
				break;
			}
		}
	}

#if (TARGET_PLATFORM == TARGET_PLATFORM_WIN)
	closesocket(st);
#else
	close(st);
#endif
}

}
