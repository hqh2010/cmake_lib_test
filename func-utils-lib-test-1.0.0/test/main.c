#include <stdio.h>

#include "utils/func_utils.h"

int main()
{
	int a = 3;
	int b = 2;
	printf("这是一个动态库和静态库调用的demo\n");
	printf("%d + %d = %d\n", a, b, func_add(a, b));
	return 0;
}
