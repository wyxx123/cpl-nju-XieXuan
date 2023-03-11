//
// Created by xiexu on 2023/2/26.
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;
	int k = 0;
	scanf("%d%d", &n, &k);

	int* array = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	int pivot = array[k - 1];

	int left = 0;
	int right = n - 1;

	while (left < right)
	{
		while (left < right && array[left] < pivot)
			left++;

		while (left < right && array[right] >= pivot)
			right--;

		if (left < right)
		{
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
		}
	}

	int pivot_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] == pivot)
		{
			pivot_index = i;
			break;
		}
	}

	// * last swap for pivot and pointed element
	int temp = array[pivot_index];
    array[pivot_index] = array[right];
    array[right] = temp;

	// * print
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

	free(array);
	return 0;
}