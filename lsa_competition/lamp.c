//
// Created by xiexu on 2022/10/29.
//



#include <stdio.h>

int FindDoubleIndex(int* input, int* double_index, int sizes);

int main(void)
{
	int sizes = 0;
	scanf("%d", &sizes);

	int input[100002] = { 0 };
	for (int i = 1; i <= sizes; i++)
	{
		scanf("%d", &input[i]);
	}
	input[0] = input[1];
	input[sizes + 1] = input[sizes];

	int double_index[100002] = { 0 };
	int count_double = FindDoubleIndex(input, double_index, sizes);

	//output
	int max_range = 0;
	if (count_double != 2)
	{
		for (int i = 1; i <= count_double - 3; i++)
		{
			int tmp_range = double_index[i + 2] - double_index[i - 1];
			max_range = (max_range >= tmp_range) ? max_range : tmp_range;
		}

		if (double_index[1] == 1)
		{
			max_range = (max_range >= double_index[2]) ? max_range : double_index[2];
		}
		if (double_index[count_double - 2] == sizes - 1)
		{
			max_range = (max_range >= (sizes - double_index[count_double - 3])) ? max_range : (sizes
				- double_index[count_double - 3]);
		}
	}
	else
	{
		max_range = sizes;
	}

	printf("%d\n", max_range);

	return 0;
}

int FindDoubleIndex(int* input, int* double_index, int sizes)
{
	int count_double = 0;
	int pro_element = input[0];
	int index_of_double_index = 0;
	for (int i = 1; i <= sizes + 1; i++)
	{
		if (input[i] == pro_element)
		{
			double_index[index_of_double_index] = i - 1;
			count_double++;
			index_of_double_index++;
		}
		pro_element = input[i];
	}

	return count_double;
}
