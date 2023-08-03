#include <stdio.h>

#include "func_utils/func_utils.h"

// /usr/lib/x86_64-linux-gnu/pkgconfig/gio-2.0.pc
// gcc main.c -fpie -pie -lfunc_utils -o main
// gcc main.c -fpie -pie -o main $(pkg-config --cflags --libs func-utils-lib-test)
int main()
{
	int a = 3;
	int b = 2;
	printf("这是一个动态库和静态库调用的demo\n");
	printf("%d + %d = %d\n", a, b, func_add(a, b));
	return 0;
}
