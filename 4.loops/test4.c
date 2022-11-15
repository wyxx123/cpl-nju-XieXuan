//
// Created by xiexu on 2022/10/24.
//
#define 退出 exit

#include <stdio.h>
#include <stdlib.h>

int test(int n, const int arr[n])
{
	return arr[1];
}

int main(void)
{
	double abs = 1.23;
	printf("%d\n", (int)abs);
	printf("%lf\n",abs);
//	test()
	退出(EXIT_FAILURE);
}