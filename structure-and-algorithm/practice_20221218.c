//
// Created by xiexu on 2022/12/18.
//


int missingNumber(int* nums, int numsSize)
{
	int ret = 0;
	for (int i = 1; i <= numsSize; i++)
	{
		ret ^= i;
		ret ^= nums[i - 1];
	}
	return ret;
}
