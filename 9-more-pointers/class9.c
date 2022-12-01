//
// Created by xiexu on 2022/11/26.
//
#include <stdio.h>

int main(void)
{
	char ch[30] = { 0 };
	int count = -1;

	while ((ch[++count] = getchar()) != EOF)
		printf("is:%c\n", ch[count]);
	return 0;
}
