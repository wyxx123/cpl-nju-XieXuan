//
// Created by xiexu on 2022/11/12.
//
#include <stdio.h>

void rotate_cubic(int* x1, int* y1, int* x2, int* y2, char* operations, int a, int b, int c);

int main(void)
{
	char operations[1001] = { 0 };
	int a = 0;
	int b = 0;
	int c = 0;

	scanf("%d%d%d%1000s", &a, &b, &c, operations);
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	rotate_cubic(&x1, &y1, &x2, &y2, operations, a, b, c);

	printf("%d %d %d %d\n", x1, x2, y1, y2);

	return 0;
}

void rotate_cubic(int* x1, int* y1, int* x2, int* y2, char* operations, int a, int b, int c)
{
	if (*operations == 0)
	{
		*x2 = *x1 + a;
		*y2 = *y1 + b;
	}

	if (*operations == 'S')
	{
		*x1 += a;
		rotate_cubic(x1, y1, x2, y2, operations + 1, c, b, a);
	}
	if (*operations == 'W')
	{
		*x1 -= c;
		rotate_cubic(x1, y1, x2, y2, operations + 1, c, b, a);
	}
	if (*operations == 'D')
	{
		*y1 += b;
		rotate_cubic(x1, y1, x2, y2, operations + 1, a, c, b);
	}
	if (*operations == 'A')
	{
		*y1 -= c;
		rotate_cubic(x1, y1, x2, y2, operations + 1, a, c, b);
	}
}
