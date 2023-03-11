//
// Created by xiexu on 2023/2/26.
//
#include <stdio.h>

void SelectSort(int* array, int size);
void Swap(int* array, int index1, int index2);

int main(void)
{
	int array[10] = { 1, 2, 3, 5, 4, 6, 8, 9, 10, 7 };
	SelectSort(array, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
		
	}

	return 0;
}

void SelectSort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = array[i];
		int min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min_index = j;
				min = array[j];
			}
		}

		Swap(array, i, min_index);
	}
}

void Swap(int* array, int index1, int index2)
{
	if (index1 == index2)
		return;
	int tmp = array[index1];
	array[index1] = array[index2];
	array[index2] = tmp;
}

