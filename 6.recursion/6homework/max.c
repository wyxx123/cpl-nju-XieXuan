//
// Created by xiexu on 2022/11/4.
//


#include <stdio.h>

int input[100000] = { 0 };
int output[100000][2] = { 0 };

void find_maximum_max_range(int left, int right);
int find_maximum_index(int left, int right);

int main(void)
{
	int sizes = 0;
	scanf("%d", &sizes);

	for (int i = 0; i < sizes; i++)
	{
		scanf("%d", input + i);
	}

	int left = 0;
	int right = sizes - 1;
	find_maximum_max_range(left, right);

	for (int i = 0; i < sizes; i++)
	{
		printf("%d %d\n", output[i][0] + 1, output[i][1] + 1);
	}

	return 0;
}

void find_maximum_max_range(int left, int right)
{
	if (left > right)
		return;

	int max_index = find_maximum_index(left, right);
	output[max_index][0] = left;
	output[max_index][1] = right;
	find_maximum_max_range(left, max_index - 1);
	find_maximum_max_range(max_index + 1, right);
}

int find_maximum_index(int left, int right)
{
	int max_index_temple = left;
	for (int pointer = left + 1; pointer <= right; pointer++)
	{
		if (input[max_index_temple] < input[pointer])
			max_index_temple = pointer;
	}
	return max_index_temple;
}

