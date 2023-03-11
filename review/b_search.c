//
// Created by xiexu on 2023/2/19.
//
#include <stdio.h>
#define MAX_N 1000010

int input[MAX_N] = { 0 };

int get(int target, int n);

int main(void)
{
	int n = 0;
	int q = 0;
	scanf("%d%d", &n, &q);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", input + i);
	}

	for (int i = 0; i < q; i++)
	{
		int target = 0;
		scanf("%d", &target);
		printf("%d\n", get(target, n));
	}

	return 0;
}

int get(int target, int n)
{
	int left = 0;
	int right = n - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (right + left) / 2;

		if (input[mid] == target)
			return mid;
		if (input[mid] > target)
			right = mid - 1;
		if (input[mid] < target)
			left = mid + 1;
	}
	return -1;
}
