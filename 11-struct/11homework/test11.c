//
// Created by xiexu on 2022/12/9.
//
#include <stdio.h>

int* CreateI(void);

int main(void)
{
	const int* a = CreateI();
	printf("%d\n", *a);

	return 0;
}

int* CreateI(void)
{
	static int i = 1;
	return &i;
}
