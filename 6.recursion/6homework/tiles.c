//
// Created by xiexu on 2022/11/4.
//
//  //o:1+(n-2)--not needed
// 0||  (0-1 1-1 2-2) 3-3 4-5  5 - 1+4+3=8
//j:3*(n-2)-(n-4)

#include <stdio.h>

int calculate_cases(int num);

int main(void)
{
	int input = 0;
	scanf("%d", &input);

	printf("%d\n", calculate_cases(input));
	return 0;
}

int calculate_cases(int num)
{
	if (num < 0)
		return 0;
	if (num <= 1)
		return 1;
	if (num == 2)
		return 2;
	else
		return 3 * calculate_cases(num - 2) - calculate_cases(num - 4);
}
