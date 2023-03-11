//
// Created by xiexu on 2022/12/22.
//

#include <stdio.h>

void RotateIntArray(int* base, int size);
void rotate(int* nums, int numsSize, int k);

int main(void)
{
	int nums[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int numsSize = 7;
	int k = 3;
	rotate(nums, numsSize, k);

	for (int i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}

	return 0;
}

void rotate(int* nums, int numsSize, int k)
{
	k %= numsSize;
	RotateIntArray(nums, numsSize - k);
	RotateIntArray(nums + (numsSize - k), k);
	RotateIntArray(nums, numsSize);
}

void RotateIntArray(int* base, int size)
{
	if (size <= 1)
		return;

	int* end = base + size - 1;

	// * swap
	int tmp = *base;
	*base = *end;
	*end = tmp;

	RotateIntArray(base + 1, size - 2);
}
