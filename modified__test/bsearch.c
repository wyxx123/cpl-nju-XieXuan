//
// Created by xiexu on 2022/12/10.
//
#include <stdio.h>

#define MAX_RANGE_N_Q 1000010

int input_array[MAX_RANGE_N_Q] = { 0 };
int Bsearch(int left_index, int right_index, int searched);

int main(void)
{
	int n = 0;
	int q = 0;
	scanf("%d%d", &n, &q);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", input_array + i);
	}

	for (int i = 0; i < q; i++)
	{
		int searched = 0;
		scanf("%d", &searched);
		printf("%d\n", Bsearch(0, n - 1, searched));
	}

	return 0;
}
int Bsearch(int left_index, int right_index, int searched)
{
	if (left_index > right_index)
		return -1;

	int mid_index = (left_index + right_index) / 2;
	if (input_array[mid_index] == searched)
		return mid_index;
	if (input_array[mid_index] > searched)
		return Bsearch(left_index, mid_index - 1, searched);
	return Bsearch(mid_index + 1, right_index, searched);
}
