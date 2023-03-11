//
// Created by xiexu on 2022/12/25.
//
#include <stdlib.h>
#include <stdio.h>

// * leetCode: https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/description/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	*returnSize = 2;

	int all_count = 0;
	for (int i = 0; i < numsSize; i++)
	{
		all_count ^= nums[i];
	}

	int first_different_bit = 0;

	while (!((1 << first_different_bit) & all_count))
		first_different_bit++;

	int zero_bit_count = 0;
	int one_bit_count = 0;

	for (int i = 0; i < numsSize; i++)
	{
		if ((1 << first_different_bit) & nums[i])
			one_bit_count ^= nums[i];
		else
			zero_bit_count ^= nums[i];
	}
	int* return_array = malloc(*returnSize * sizeof(*return_array));
	return_array[0] = zero_bit_count;
	return_array[1] = one_bit_count;
	return return_array;
}


//27. 移除元素  https://leetcode.cn/problems/remove-element/

void Swap(int* nums, int cur_index, int swap_index);

int removeElement(int* nums, int numsSize, int val)
{
	int swap_index = numsSize - 1;
	int cur_index = 0;

	while (cur_index <= swap_index)
	{
		if (nums[cur_index] != val)
			cur_index++;
		else if (nums[swap_index] == val && cur_index != swap_index)
		{
			swap_index--;
			Swap(nums, cur_index, swap_index);
			swap_index--;
		}
		else
		{
			Swap(nums, cur_index, swap_index);
			swap_index--;
		}
	}
	return swap_index + 1;
}

void Swap(int* nums, int cur_index, int swap_index)//其实不用交换，赋值即可。 : 将val移除 -> 将非val移入
{
	int tmp = nums[cur_index];
	nums[cur_index] = nums[swap_index];
	nums[swap_index] = tmp;
}

// 删除重复项： https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
int removeDuplicates(int* nums, int numsSize);

int main(void)
{
	int num[3] = { 1, 1, 2 };
	int ret = removeDuplicates(num, 3);

	for (int i = 0; i < ret; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}

int removeDuplicates(int* nums, int numsSize)
{
	int dest = 0;
	int cur_val = -1000000;

	for (int src = 0; src < numsSize; src++)
		if (cur_val != nums[src])
			cur_val = nums[dest++] = nums[src];

	return dest;
}

// * 88.合并两个升序数组  https://leetcode.cn/problems/merge-sorted-array/


void err_merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int nums1_index = 0;
	int nums2_index = 0;

	//你在幹森麽？
	//! 2n + 2m = n + m -- 常数忽略！
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int index1 = m - 1;
	int index2 = n - 1;
	int dest = nums1Size - 1;

	while (index1 >= 0 && index2 >= 0)
	{
		if (nums1[index1] > nums2[index2])
		{
			nums1[dest] = nums1[index1];
			index1--;
		}
		else
		{
			nums1[dest] = nums2[index2];
			index2--;
		}
		dest--;
	}

	while (index2 >= 0)
		nums1[dest--] = nums2[index2--];

}