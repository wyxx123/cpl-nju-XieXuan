//
// Created by xiexu on 2022/10/1.
//

#include <stdio.h>

int main()
{
	int count = 0;
	int failure = 0;
	int size = 0;
	int num[200000] = { 0 };
	int i = 0;
	int j = 0;
	int flag = 0;
	int cmp = 0;
	scanf("%d", &size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", num + i);
	}

	for (i = 0; i < 3; i++)
	{
		flag = 1;
		while (flag)
		{
			flag = 0;
			for (j = 0; j < size - 1 - count; j++)
			{
				if (num[j] > num[j + 1])
				{
					int swap = num[j];
					num[j] = num[j + 1];
					num[j + 1] = swap;
				}
				else if (num[j] == num[j + 1])
				{
					flag = 1;
					cmp = num[j];
				}
				if (i == 2 && flag == 1)
				{
					failure = 1;
				}
			}
			count++;
			if (flag == 1 && cmp != num[size - count])
			{
				flag = 0;
			}

		}

	}
	if ((size > 2 && count <= size) && failure != 1)
	{
		printf("%d\n", num[size - count]);
	}
	else
	{
		printf("%d\n", num[size - 1]);
	}
	return 0;
}
