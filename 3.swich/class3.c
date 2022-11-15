//
// Created by xiexu on 2022/10/14.
//

#define LEN 10

#include <stdio.h>

int main(void)
{
	int array[LEN] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
	int left = 0;
	int right = LEN - 1;
	int mid = 0;
	int key = 0;
	int ret = -1;

	scanf("%d", &key);

	do
	{
		mid = (left + right) / 2;
		if (array[mid] < key)
		{
			left = mid + 1;
		}
		else if (array[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			ret = mid;
			right = mid - 1;
		}
	} while (left <= right);

	printf("%d\n", ret);

	return 0;
}
