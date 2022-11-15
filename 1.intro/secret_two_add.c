//
// Created by xiexu on 2022/10/3.
//
#include <stdio.h>

int main(void)
{
	int size = 0;
	int num_input[10000] = { 0 };
	int target = 0;
	int i = 0;
	int j = 0;
	int flag = 0;

	scanf("%d", &size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", num_input + i);
	}
	scanf("%d", &target);

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (num_input[i] + num_input[i + j + 1] == target)
			{
				printf("%d %d\n", i, i + j + 1);
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	return 0;
}
