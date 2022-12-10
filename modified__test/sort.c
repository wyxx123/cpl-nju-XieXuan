//
// Created by xiexu on 2022/12/10.
//
#include <stdio.h>
#include <stdbool.h>

#define LEN_MAX 1010

int main(void)
{
	int T = 0;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int m = 0;
		int n = 0;
		scanf("%d%d", &m, &n);

		int input_array[LEN_MAX] = { 0 };
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", input_array + j);
		}

		for (int j = 0; j < m; j++)
		{
			int oped_index = 0;
			scanf("%d", &oped_index);

			int tmp = input_array[oped_index];

			for (int k = oped_index; k > 0; k--)
			{
				input_array[k] = input_array[k - 1];
			}

			input_array[1] = tmp;
		}

		bool flag = true;
		for (int j = 1; j < n; j++)
		{
			if (input_array[j] > input_array[j + 1])
			{
				flag = false;
				break;
			}
		}

		if (flag)
			printf("I love C programming language\n");
		else
			printf("mayi is a good teacher\n");
	}

	return 0;
}