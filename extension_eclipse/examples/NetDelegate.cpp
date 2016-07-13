#include "NetDelegate.h"
#include "msgid.h"

NetDelegate::NetDelegate()
{
}

NetDelegate::~NetDelegate()
{

}

void NetDelegate::onMessageReceived(SOCKET st, extension::Buffer& buffer)
{
	unsigned int id = buffer.readUInt();

	switch (id)
	{
	case msgid_req_download:
		{
#pragma region 
			std::string filenametemp = buffer.readString();

			char curpath[_MAX_PATH];
#if (TARGET_PLATFORM == TARGET_PLATFORM_WIN)
			_getcwd(curpath, _MAX_PATH);
#elif (TARGET_PLATFORM == TARGET_PLATFORM_LINUX)
			getcwd(curpath,  _MAX_PATH);
#endif

			std::string filename;
			filename.clear();
			filename.assign(curpath);
			filename.append("/");
			filename.append(filenametemp);

			FILE *fd = fopen(filename.c_str(), "rb");
			
			if (fd == NULL)
			{
				break;
			}
			char buf[1024*8];
			
			extension::Buffer buffer;
			buffer.clear();
			buffer.writeInt(msgid_res_download_create);
			buffer.writeString(filenametemp.c_str());
			sendm(st, buffer);

			while (true)
			{
				memset(buf, 0, sizeof(buf));
				int rc = fread(buf, sizeof(char), sizeof(buf), fd);
				if (rc <= 0)
				{
					break;
				}
				else
				{
					buffer.clear();
					buffer.writeInt(msgid_res_download_data);
					buffer.writeString(filenametemp.c_str());
					buffer.writeInt(rc);
					buffer.writeData(buf, rc);
					sendm(st, buffer);
				}
			}

			fclose(fd);
			buffer.clear();
			buffer.writeInt(msgid_res_download_close);
			buffer.writeString(filenametemp.c_str());
			sendm(st, buffer);
#pragma endregion 
		}
		break;
	case msgid_req_scan:
#pragma region
	{
		int clientversion = buffer.readInt();

		std::vector<FileInfo*> vfiles;

		if (FileManager::getInstance()->getClientVersion() == clientversion)
		{

		} else
		{
			int num = buffer.readInt();

			for (int i = 0; i < num; i++)
			{
				std::string filepath = buffer.readString();
				int filesize = buffer.readInt();
				std::string lastupdatetime = buffer.readString();
				int version = buffer.readInt();
				int isdir = buffer.readInt();

				FileInfo* fileinfo = new FileInfo();
				fileinfo->FileRelativePath = filepath.c_str();
				fileinfo->FileSize = filesize;
				fileinfo->LastUpdateTime = lastupdatetime.c_str();
				fileinfo->Version = version;
				fileinfo->m_bdir = isdir;
				vfiles.push_back(fileinfo);
			}
		}
		
		FileManager::getInstance()->scanfiles("FileFolder", vfiles);

		//send
		extension::Buffer buffer;
		buffer.clear();
		buffer.writeInt(msgid_res_scanover);
		buffer.writeInt(FileManager::getInstance()->getClientVersion());
		buffer.writeInt(vfiles.size());



		std::vector<FileInfo*>::iterator it;
		for (it = vfiles.begin(); it != vfiles.end(); ++it)
		{
			FileInfo* obj = *it;

			if (obj->m_bdir)
			{
				buffer.writeString(obj->FileRelativePath.c_str());
				buffer.writeInt(obj->FileSize);
				buffer.writeString(obj->LastUpdateTime.c_str());
				buffer.writeInt(obj->Version);
				buffer.writeInt(obj->m_echange);
				buffer.writeInt(obj->m_bdir);
				delete obj;
			}
		}

		for (it = vfiles.begin(); it != vfiles.end(); ++it)
		{
			FileInfo* obj = *it;

			if (!obj->m_bdir)
			{
				buffer.writeString(obj->FileRelativePath.c_str());
				buffer.writeInt(obj->FileSize);
				buffer.writeString(obj->LastUpdateTime.c_str());
				buffer.writeInt(obj->Version);
				buffer.writeInt(obj->m_echange);
				buffer.writeInt(obj->m_bdir);

				delete obj;
			}
		}

		sendm(st, buffer);
	}
#pragma endregion
		break;
	default:
		break;
	}
}
