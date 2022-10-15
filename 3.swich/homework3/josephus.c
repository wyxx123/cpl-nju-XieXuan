//
// Created by xiexu on 2022/10/14.
//
#include <stdio.h>

int func(int n, int k)
{
	if (n > 0)
	{
		int ret = k + func(n - 1, k);
		return (ret - 1) % n + 1;
	}
	return 1;
}

int main(void)
{
	int n = 0;
	int k = 0;
	scanf("%d%d", &n, &k);

	printf("%d\n", func(n, k));

	return 0;
}