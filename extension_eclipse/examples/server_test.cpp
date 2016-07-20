#include "../src/extension.h"
#include "NetDelegate.h"
using namespace extension;

/**
 * 	valgrind --tool=memcheck --leak-check=full ./extension_eclipse
 *
 * **/

int main()
{
	NetDelegate::sharedDelegate()->startserver(8080);

	void *data = malloc(100);
	free(data);

	int i = 100;
	while(i-- > 0)
	{
		std::string filespath = "FileFolder";
		FileManager::getInstance()->startScanning(filespath.c_str());
		printf("scanning over\n");

		//sleep one hour
		printf("main thread sleeping...\n");
//		sleep(60*0.5);
//		sleep(60*0.5);
	}
	return 0;
}
