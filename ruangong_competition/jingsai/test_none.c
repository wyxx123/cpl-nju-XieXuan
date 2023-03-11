//
// Created by xiexu on 2022/11/21.
//
#include <stdio.h>

#define MAX_TIME 100

int main(void)
{
	int test = 1;
	for (int i = 0; i < MAX_TIME; i++)
	{
		printf("%d\n", i + test);
	}
	return 0;
}