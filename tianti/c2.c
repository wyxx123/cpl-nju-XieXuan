//
// Created by xiexu on 2023/1/8.
//
#include <stdio.h>
#include <stdlib.h>

long long Judge(int* input, int input_size, int count);

int main(void)
{
	int times = 0;
	scanf("%d", &times);
	for (int i = 0; i < times; i++)
	{
		int input_size = 0;
		scanf("%d", &input_size);
		int* input = malloc(input_size * sizeof *input);
		for (int j = 0; j < input_size; j++)
		{
			scanf("%d", &input[j]);
		}

		int count = 0;
		for (int j = 0; j < input_size; j++)
		{
			count += input[j];
		}
		printf("%lld\n", 2023 * Judge(input, input_size, count));
		free(input);
	}
	return 0;
}

long long Judge(int* input, int input_size, int count)
{
	int true_count = (count == 0) ? 1 : 0;
	int term_count = count;
	for (int i = input_size - 1; i > 0; i--)
	{
		term_count -= input[i];
		if (!term_count)
			true_count++;
	}
	return (input_size == 1) ? true_count
							 : true_count + Judge(input + 1, input_size - 1, count - *input);
}
