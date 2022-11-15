//
// Created by xiexu on 2022/11/4.
//





#include <stdio.h>

int find_pyramid_num(int row, int col);

int main(void)
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);

	printf("%d\n", find_pyramid_num(a, b));
	return 0;
}

int find_pyramid_num(int row, int col)
{
	if ((col == 1) || (col == row))
		return 1;
	return find_pyramid_num(row - 1, col - 1) + find_pyramid_num(row - 1, col);
}
