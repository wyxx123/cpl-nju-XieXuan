//
// Created by xiexu on 2023/2/26.
//
#include <stdio.h>

void Judge(int p, int q, int r);
int Modified(int source, int basis);

int main(void)
{
	int p = 0;
	int q = 0;
	int r = 0;
	scanf("%d%d%d", &p, &q, &r);

	Judge(p, q, r);

	return 0;
}

void Judge(int p, int q, int r)
{
	for (int i = 2; i <= 40; i++)
	{
		if (i <= p / 10 || i <= p % 10
				|| i <= q / 10 || i <= q % 10
				|| i <= r / 10 || i <= r % 10)
			continue;

		int modified_p = Modified(p, i);
		int modified_q = Modified(q, i);
		int modified_r = Modified(r, i);

		if (modified_p * modified_q == modified_r)
		{
			printf("%d\n", i);
			return;
		}
	}

	printf("0\n");
}

int Modified(int source, int basis)
{
	int first_bit = source % 10;
	int second_bit = source / 10;
	return (first_bit + second_bit * basis);
}

