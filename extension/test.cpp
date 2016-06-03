#include "extension.h"

using namespace extension;

int main()
{
	double d = XTimeUtil::getSystemTimeForSecond();

	printf("%f\n", d);
	return 0;
}
