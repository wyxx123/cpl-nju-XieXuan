#include <stdio.h>
#include <string.h>

int ack(int m, int n)
{
	while (m != 0)
	{
		if (n == 0) n = 1;
		else
		{
			n = ack(m, n - 1);
		}
		m--;
	}
	return n + 1;
}

int main(void)
{
	printf("%d\n", ack(3, 10));
	return 0;
}
