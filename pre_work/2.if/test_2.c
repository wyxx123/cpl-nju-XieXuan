//
// Created by xiexu on 2022/10/9.
//

#include <stdio.h>

int main(void)
{
	double a = 1.0 / 5;
	long double b = 1.0 / 5;
	printf("%.20lf,%.20Lf", a, b);
}