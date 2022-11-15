//
// Created by xiexu on 2022/10/11.
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[6], i = 0, s, sm, su;
	for (i = 0; i < 6; i++)
		scanf("%d", &a[i]);

	if (a[0] != a[2] && a[1] != a[3])
	{
		s = abs(a[2] - a[0]) + abs(a[1] - a[3]);
		printf("%d\n", s);
		sm = abs(a[2] - a[0]); //delta x
		su = abs(a[1] - a[3]); //delta y
		if (a[1] != a[5] && a[2] != a[4]) //0.xa  1.ya  2.xb  3.yb  4.xc  5.yc
		{
			if (a[0] > a[2])
			{
				for (i = 0; i < sm; i++)
				{
					printf("L");
				}
			}
			else
			{
				for (i = 0; i < sm; i++)
				{
					printf("R");
				}
			}
			if (a[1] > a[3])
			{
				for (i = 0; i < su; i++)
				{
					printf("D");
				}
			}
			else
			{
				for (i = 0; i < su; i++)
				{
					printf("U");
				}
			}
		}
		else
		{
			if (a[1] > a[3])
			{
				for (i = 0; i < su; i++)
				{
					printf("D");
				}
			}
			else
			{
				for (i = 0; i < su; i++)
				{
					printf("U");
				}
			}
			if (a[0] > a[2])
			{
				for (i = 0; i < sm; i++)
				{
					printf("L");
				}
			}
			else
			{
				for (i = 0; i < sm; i++)
				{
					printf("R");
				}
			}
		}
	}
	else
	{//0.xa  1.ya  2.xb  3.yb  4.xc  5.yc
		if ((a[0] == a[2] && a[2] == a[4] && (a[1] < a[5] && a[5] < a[3] || a[1] > a[5] && a[5] > a[3]))
			|| (a[1] == a[3] && a[3] == a[5] && (a[0] < a[4] && a[4] < a[2] || a[0] > a[4] && a[4] > a[2]))) // 2 kind
		{
			s = abs(a[2] - a[0]) + abs(a[1] - a[3]) + 2;
			printf("%d\n", s);
			if (a[0] < a[2])
			{
				printf("U");
				for (i = 0; i < s - 2; i++)
				{
					printf("R");
				}
				printf("D");
			}
			if (a[0] > a[2])
			{
				printf("U");
				for (i = 0; i < s - 2; i++)
				{
					printf("L");
				}
				printf("D");
			}
			if (a[1] < a[3])
			{
				printf("L");
				for (i = 0; i < s - 2; i++)
				{
					printf("U");
				}
				printf("R");
			}
			if (a[1] > a[3])
			{
				printf("L");
				for (i = 0; i < s - 2; i++)
				{
					printf("D");
				}
				printf("R");
			}
		}
		else // 3 kind
		{
			s = abs(a[2] - a[0]) + abs(a[1] - a[3]);
			printf("%d\n", s);
			if (a[0] < a[2])
			{
				for (i = 0; i < s; i++)
				{
					printf("R");
				}
			}
			if (a[0] > a[2])
			{
				for (i = 0; i < s; i++)
				{
					printf("L");
				}
			}
			if (a[1] < a[3])
			{
				for (i = 0; i < s; i++)
				{
					printf("U");
				}
			}
			if (a[1] > a[3])
			{
				for (i = 0; i < s; i++)
				{
					printf("D");
				}
			}
		}
	}
	return 0;
}