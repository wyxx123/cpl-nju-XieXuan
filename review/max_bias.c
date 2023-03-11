//
// Created by xiexu on 2023/2/7.
//
#include <stdio.h>

#define DEFAULT_LENGTH 1000000

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int input[DEFAULT_LENGTH] = { 0 };

int main(void)
{
	int count = 0;
	while (scanf("%d", &input[count++]) != EOF);

	long max_bias = 0;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			max_bias = MAX(max_bias, (long)input[j] - input[i]);
		}
	}

	printf("%ld\n", (max_bias > 0) ? max_bias : -1);

	return 0;
} //?