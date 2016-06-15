#include "extension.h"

using namespace extension;

int main()
{
	double d = XTimeUtil::getSystemTimeForSecond();

	printf("%f\n", d);

	std::string filespath = "FileFolder";
	FileManager::getInstance()->startScanning(filespath.c_str());

	return 0;
}


//#include <stdlib.h>
//#include <stdio.h>
//int main()
//{
//	printf("hello");
//
//	return 0;
//}
