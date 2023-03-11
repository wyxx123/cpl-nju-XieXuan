//
// Created by xiexu on 2023/2/26.
//
#include <stdio.h>

#define L_LENGTH 10
#define R_LENGTH 10

void MergeSort(int* l_array, int* r_array, int* merged_array);

int main(void)
{
	int l_array[L_LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int r_array[R_LENGTH] = { 2, 4, 6, 8, 9, 11, 14, 15, 18, 20 };
	int merged_array[L_LENGTH + R_LENGTH] = { 0 };

	MergeSort(l_array, r_array, merged_array);

	for (int i = 0; i < L_LENGTH + R_LENGTH; i++)
	{
		printf("%d ", merged_array[i]);
	}

	return 0;
}

void MergeSort(int* l_array, int* r_array, int* merged_array)
{
	int l_cur = 0;
	int r_cur = 0;
	int merged_cur = 0;

	while (l_cur < L_LENGTH && r_cur < R_LENGTH)
	{
		if (l_array[l_cur] < r_array[r_cur])
		{
			merged_array[merged_cur++] = l_array[l_cur++];
		}
		else // l_array[l_cur] >= r_array[r_cur]
		{
			merged_array[merged_cur++] = r_array[r_cur++];
		}
	}

	while (l_cur < L_LENGTH)
		merged_array[merged_cur++] = l_array[l_cur++];

	while (r_cur < R_LENGTH)
		merged_array[merged_cur++] = r_array[r_cur++];
}
