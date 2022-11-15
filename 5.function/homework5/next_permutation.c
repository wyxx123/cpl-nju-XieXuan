//
// Created by xiexu on 2022/10/28.
//

/*
 * 1 2 3
 * 1 3 2
 *
 * 2 1 3
 * 2 3 1
 *
 * 3 1 2
 * 3 2 1
 *
 * 1 2 3 4
 * 1 2 4 3
 *
 * 1 3 2 4
 * 1 3 4 2
 *
 * 1 4 2 3
 * 1 4 3 2
 *
 * 2 ``
 *
 *求下一个排列的方法
找出给出的排列的最长连续递降后缀，其长度记为 m(m < n)m(m<n)。
找到最长递降后缀的之前的那个数，记为 p_kp
k

 ，在最长递降后缀中找到比大于 p_kp
k

  的数中最小的那个，交换这两个数。
将交换后的序列的后 mm 个数翻转。
 *
 *int sizes = 0;
 * char one_back_crime[2000] = {0};
 *
 * scanf sizes
 * for(1f0) - scanf(" %c",one_back_crime[i])
 *
 * int (m)max_drop_range = FindMaxDropRange(one_back_crime, sizes)
 * index_pro_char(pk) = sizes-1-m
 * int index_min_char  = FindMinIndex(one_back_crime,m, sizes, one_back_crime[i_p_c])
 * SwapChar(one_back_crime,index_min_char,index_pk)
 * SwapCharArray(one_back_crime, m, sizes)  *not qsort*
 * PrintArray(one_back_crime,sizes)
 *
 *
 * FindMaxDropRange(one_back_crime, sizes)
 * for(int i = 0; i < sizes - 1; i++)  *?*
 * if(one_back_crime[s-1-i] > one_back_crime[s-2-i])
 *   return i+1;
 *
 * FindMinIndex(one_back_crime,m, sizes,char)
 *   for(int i = 0 ;< sizes-1)
 *    if(one_back_crime[sizes-1-i]>char)
 *    return sizes -1 -i;
 *
 * SwapChar(one_back_crime,index_min_char,index_pk)
 *  int tmp = ``
 *
 * SwapCharArray(one_back_crime, m, sizes)
 *   //qsort();
 *   char* left = one_back_crime +sizes -m,right=one_back_crime +sizes -1;
 *   while(left<right)
 *   char tmp``
 *   l++
 *   r--
 *
 * PrintArray(one_back_crime,sizes)
 *   for(if0 <sizes-1)
 *   printf``
 *
 */

#include <stdio.h>

int FindMaxDropRange(const int* input, int sizes);
int FindMinIndex(const int* input, int max_drop_range, int sizes, int pro_char);
void SwapChar(int* input, int index_min_char, int index_pro_char);
void SwapCharArray(int* input, int max_drop_range, int sizes);
void PrintArray(const int* input, int sizes);

int main(void)
{
	int sizes = 0;
	int input[2000] = { 0 };

	scanf("%d", &sizes);
	for (int i = 0; i < sizes; i++)
	{
		scanf(" %d", input + i);
	}

	int max_drop_range = FindMaxDropRange(input, sizes);
	int index_pro_char = sizes - 1 - max_drop_range;
	int index_min_char = FindMinIndex(input, max_drop_range, sizes, input[index_pro_char]);
	SwapChar(input, index_min_char, index_pro_char);
	SwapCharArray(input, max_drop_range, sizes);
	PrintArray(input, sizes);

	return 0;
}

int FindMaxDropRange(const int* input, int sizes)
{
	for (int i = 0; i < sizes - 1; i++)
	{
		if (input[sizes - i - 1] > input[sizes - i - 2])
			return i + 1;
	}
	return -1;
}

// /**
//  *
//  * @param one_back_crime the array one_back_crime by you
//  * @param max_drop_range the maximum of the scope of droping
//  * @param sizes the sizes of array
//  * @param pro_char the pro char
//  * @return -1 err \n
//  *         others  correct
//  */
int FindMinIndex(const int* input, int max_drop_range, int sizes, int pro_char)
{
	for (int i = 0; i < max_drop_range; i++)
	{
		if (input[sizes - 1 - i] > pro_char)
			return sizes - i - 1;
	}
	return -1;
}

void SwapChar(int* input, int index_min_char, int index_pro_char)
{
	int tmp = input[index_pro_char];
	input[index_pro_char] = input[index_min_char];
	input[index_min_char] = tmp;
}

void SwapCharArray(int* input, int max_drop_range, int sizes)
{
	const int* left = input + sizes - max_drop_range;
	const int* right = input + sizes - 1;
	const int* tmp = left;
	while (left < right)
	{
		SwapChar(input, sizes - max_drop_range + left - tmp, sizes - max_drop_range + right - tmp);
		left++;
		right--;
	}
}

void PrintArray(const int* input, int sizes)
{
	for (int i = 0; i < sizes; i++)
	{
		printf("%d ", input[i]);
	}
}


