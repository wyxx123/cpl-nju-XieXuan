//#define 一只最强的9 0
//#define ⑨ void

//
// Created by ⑨ on 9999/99/99.
//
//
//int main(⑨)
//{
//	printf("%s\n","⑨是最强的！！！");
//	return 一只最强的9;
//}



#include <stdlib.h>

int CompareInt(const void* num1, const void* num2)
{
	return *(const int*)num1 - *(const int*)num2;
}

int missingNumber(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof *nums, CompareInt);

	int i = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (i != nums[i])
			return i;
	}
	return i;
}



