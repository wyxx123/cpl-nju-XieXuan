//
// Created by xiexu on 2022/11/6.
//



#include <stdio.h>

int max(int num1, int num2);

int input[1000000] = { 0 };
int bias[1000000] = { 0 };

int main(void)
{
	int num_of_group = 0;
	scanf("%d", &num_of_group);

	for (int i = 0; i < num_of_group; i++)
	{
		scanf("%d", input + i);
	}

	//find max range.
	int max_range = 0;
	for (int i = 0; i < num_of_group - 1; i++)
	{
		max_range = max(max_range, input[i + 1] - input[i]);
	}

	//get bias.
	for (int i = 1; i < num_of_group; i++)
	{
		bias[i] = bias[i - 1] + (input[i - 1] + max_range - input[i]);
	}

	printf("%d\n", bias[num_of_group - 1]);
	for (int i = 0; i < num_of_group; i++)
	{
		printf("%d ", input[i] + bias[i]);
	}

	return 0;
}

int max(int num1, int num2)
{
	return (num1 < num2) ? num2 : num1;
}

//write and pass in less than 10 minutes.
//oh yeah!!!

