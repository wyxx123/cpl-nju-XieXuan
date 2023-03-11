//
// Created by xiexu on 2023/2/7.
//
#include <stdio.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int array[101] = { 0 };

	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		array[tmp]++;
	}

	//count
	int count_array[10] = { 0 };
	for (int low = 0, high = 9; high <= 99; low += 10, high += 10)
	{
		for (int i = low; i <= high; i++)
		{
			count_array[(high + 1) / 10 - 1] += array[i];
		}
	}
	count_array[9] += array[100];


	//first line.
	for (int i = 0; i < 10; i++)
	{
		printf("%d", count_array[i]);
		if (i != 9)
			printf(",");
	}
	printf("\n");

	//more.
	for (int low = 0; low <= 90; low += 10)
	{
		printf("%2d -%3d:", low, low + ((low == 90) ? 10 : 9));
		for (int i = 0; i < count_array[(low + 1) / 10]; i++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}