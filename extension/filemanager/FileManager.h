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
#include "../extensionmacros.h"

class FileInfo
{
public:
	bool m_bdir;
	std::string FileRelativePath;
	long FileSize;
	std::string LastUpdateTime;
	unsigned int Version;
	enum CHANGE_TYPE
	{
		CHANGE_TYPE_NONE = 0,
		CHANGE_TYPE_CHANGE,
		CHANGE_TYPE_ADD,
		CHANGE_TYPE_DEL
	};
	CHANGE_TYPE m_echange;

	FileInfo()
	{
		m_bdir = false;
		FileSize = 0;
		Version = 0;
		m_echange = CHANGE_TYPE_NONE;
	}

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
	std::string m_sXmlFilePath;
	unsigned int ClientVersion;
	std::vector<FileInfo*> m_vFiles;

	void save(std::string path);
	void read(std::string path);
	void scandir(std::vector<FileInfo*>& vallfiles, std::string dirpath);
	void scanfile(std::vector<FileInfo*>& vallfiles, std::string filepath, bool bdir);
public:
	void startScanning(const char* scandir);
	void scanfiles(std::string scandir, std::vector<FileInfo*>& vallfiles);

	//set get
public:
	std::vector<FileInfo*>& getFiles();
	unsigned int getClientVersion();
};
