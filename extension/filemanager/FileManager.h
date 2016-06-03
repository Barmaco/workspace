/*************************************************
Copyright:
Author:Barmaco
Qq:992077171
Date:2016-03-21
Description:
**************************************************/
#pragma once
#include <stdlib.h>
#include "../tinyxml/tinyxml.h"
#include <string>
#include <vector>

class FileInfo
{
public:
	bool m_bdir = false;
	//�ļ����·��
	std::string FileRelativePath = "";
	//�ļ���С
	long FileSize = 0;
	//�ļ��ϴ��޸�ʱ��
	std::string LastUpdateTime = "";
	//���ļ��汾��
	unsigned int Version = 0;
	//�ļ�������Щ�仯
	typedef enum CHANGE_TYPE
	{
		CHANGE_TYPE_NONE = 0,
		CHANGE_TYPE_CHANGE,		//�仯
		CHANGE_TYPE_ADD,		//����
		CHANGE_TYPE_DEL			//ɾ��
	};
	CHANGE_TYPE m_echange = CHANGE_TYPE_NONE;

	virtual TiXmlElement* totixmlelement()
	{
		TiXmlElement *element = new TiXmlElement("FileInfo");
		element->SetAttribute("FileRelativePath", FileRelativePath.c_str());
		element->SetAttribute("FileSize", FileSize);
		element->SetAttribute("LastUpdateTime", LastUpdateTime.c_str());
		element->SetAttribute("Version", Version);
		element->SetAttribute("echange", m_echange);
		element->SetAttribute("m_bdir", m_bdir);
		return element;
	};

	virtual bool analysis(TiXmlElement *element)
	{
		if (element == NULL)
			return false;
		FileRelativePath.assign(element->Attribute("FileRelativePath"));
		FileSize = atol(element->Attribute("FileSize"));
		LastUpdateTime.assign(element->Attribute("LastUpdateTime"));
		Version = atoi(element->Attribute("Version"));
		m_echange = (CHANGE_TYPE)atoi(element->Attribute("echange"));
		m_bdir = atoi(element->Attribute("m_bdir"));
		return true;
	}

	//��ͬ���ļ��ж��Ƿ�仯����
	static bool ischange(FileInfo* fileinfo1, FileInfo* fileinfo2)
	{
		if (issamefile(fileinfo1, fileinfo2))
		{
			if (fileinfo1->FileSize != fileinfo2->FileSize ||
				fileinfo1->LastUpdateTime != fileinfo2->LastUpdateTime)
			{
				return true;
			} 
		}
		return false;
	}

	static bool issamefile(FileInfo* fileinfo1, FileInfo* fileinfo2)
	{
		if (fileinfo1->FileRelativePath == fileinfo2->FileRelativePath)
		{
			return true;
		}
		return false;
	}
};

class FileManager
{
private:
	static FileManager* m_pInstance;
	FileManager();
	virtual ~FileManager();

public:
	static FileManager* getInstance();
	static void deleteInstance();

private:
	std::string m_sscandir;
	//�ļ�ϵͳ����xml�浵���·��
	std::string m_sXmlFilePath;
	//�ļ�ϵͳ�汾
	unsigned int ClientVersion;
	//�����ļ�
	std::vector<FileInfo*> m_vFiles;

	//����
	void save(std::string path);
	//��ȡ
	void read(std::string path);
	//ɨ���ļ���
	void scandir(std::vector<FileInfo*>& vallfiles, std::string dirpath);
	//ɨ���ļ�
	void scanfile(std::vector<FileInfo*>& vallfiles, std::string filepath, bool bdir);
public:
	//��ʼɨ��
	void startScanning(const char* scandir);
	void scanfiles(std::string scandir, std::vector<FileInfo*>& vallfiles);

	//set get
public:
	std::vector<FileInfo*>& getFiles();
	unsigned int getClientVersion();
};
