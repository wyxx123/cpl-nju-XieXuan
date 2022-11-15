//
// Created by xiexu on 2022/10/15.
//

#include <stdio.h>

int main(void)
{
	int i = 0;
	int count = 0;

	scanf("%d", &i);
	for (int j = 0; j < 32; j++)
	{
		if (i & (1 << j))
		{
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}
