#include "../src/extension.h"
#include "NetDelegate.h"
using namespace extension;

int main()
{
	NetDelegate::sharedDelegate()->startserver(8080);

	while(1)
	{
		std::string filespath = "FileFolder";
		FileManager::getInstance()->startScanning(filespath.c_str());
		printf("scanning over\n");

		//sleep one hour
		printf("main thread sleeping...\n");
		sleep(60*0.5);
	}
	return 0;
}
