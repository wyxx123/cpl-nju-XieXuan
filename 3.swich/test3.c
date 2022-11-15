//
// Created by xiexu on 2022/10/15.
//
#include <stdio.h>

int main(void)
{
	int a = 0;
	if (0 && (++a) || 1)
	{
		;
	}
	printf("%d", a);
	// 0
	// && > ||
	return 0;
}