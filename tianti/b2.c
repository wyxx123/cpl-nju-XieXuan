//
// Created by xiexu on 2023/1/8.
//

#include <stdio.h>

int main(void)
{
	int input[4] = { 0 };
	scanf("%d.%d.%d.%d", input, input + 1, input + 2, input + 3);
	for (int i = 0; i < 4; i++)
	{
		int array[8] = { 0 };
		int num = input[i];
		int count = 0;
		while (num)
		{
			array[count++] = num % 2;
			num /= 2;
		}

		for (int j = 7; j >= 0; j--)
		{
			printf("%d", array[j]);
		}
	}

	return 0;
}