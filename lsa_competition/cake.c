//
// Created by xiexu on 2022/10/29.
//
#include <stdio.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int pieces = 4;

	if (n == 1)
	{
		printf("0\n");
		return 0;
	}
	else if (n == 2)
	{
		printf("2\n");
		return 0;
	}
	else if (n == 3)
	{
		printf("4\n");
		return 0;
	}
	else
	{
		for (int i = 4; i <= n; i++)
		{
			for (int k = 1; k <= i - 3; k++)
			{
				pieces += k * (i - 2 - k);
			}
			pieces += i - 1;
		}
	}

	printf("%d\n", pieces);

	return 0;
}