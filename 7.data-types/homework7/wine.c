//
// Created by xiexu on 2022/11/11.
//
#include <stdio.h>

void swap_two_elements(int index1, int index2, int* array1, int* array2);
void swap_elements(int index1, int index2, int* array);

int main(void)
{
	int n = 0;
	int L = 0;
	int values[10000] = { 0 };
	int max_volume[10000] = { 0 };

	scanf("%d%d", &n, &L);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", values + i);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", max_volume + i);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int max_index = n - 1;
		int max_values = values[n - 1];
		for (int j = n - 1; j >= i; j--)
		{
			if (values[j] > max_values)
			{
				max_index = j;
				max_values = values[j];
			}
		}

		swap_two_elements(max_index, i, values, max_volume);
	}

	//print
	int now_print_index = 0;
	int aggregated_values = 0;
	do
	{
		if (max_volume[now_print_index] <= L)
		{
			aggregated_values += max_volume[now_print_index] * values[now_print_index];
			L -= max_volume[now_print_index];
		}
		else
		{
			aggregated_values += L * values[now_print_index];
			L = 0;
		}
		now_print_index++;
	} while (L > 0);

	printf("%d\n", aggregated_values);

	return 0;
}

void swap_two_elements(int index1, int index2, int* array1, int* array2)
{
	if (index2 == index1)
		return;

	swap_elements(index1, index2, array1);
	swap_elements(index1, index2, array2);
}

void swap_elements(int index1, int index2, int* array)
{
	array[index1] ^= array[index2];
	array[index2] ^= array[index1];
	array[index1] ^= array[index2];
}
