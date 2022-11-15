//
// Created by xiexu on 2022/10/30.
//



#include <stdio.h>

#define SIZE 401

int method_length[SIZE][SIZE] = { 0 };
int waiting_time[SIZE] = { 0 };
int walking_time[SIZE][SIZE] = { 0 };
int min_time[SIZE] = { 0 };
int function_array[3][SIZE] = { 0 };

void CulculateWalkingTime(int walking_time_f[SIZE][SIZE], int count_loop, int method_length_f[SIZE][SIZE]);

int main(void)
{
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);

	for (int i = 1; i <= m; i++)
	{
		int tmp1 = 0;
		int tmp2 = 0;
		scanf("%d%d", &tmp1, &tmp2);
		scanf("%d", &method_length[tmp2][tmp1]);
		method_length[tmp1][tmp2] = method_length[tmp2][tmp1];
	}

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &waiting_time[i]);
	}

	for (int i = 1; i <= n; i++)
		CulculateWalkingTime(walking_time, i, method_length);

	for (int i = 1; i <= n; i++)
	{
		min_time[i] = 0;
		for (int j = 1; j <= n; j++)
		{
			int max = (i > j) ? i : j;
			int min = (i < j) ? i : j;
			int tmp = walking_time[min][max] + waiting_time[j];
			if (tmp < min_time[i])
			{
				min_time[i] = tmp;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", min_time[i]);
	}

	return 0;
}

void CulculateWalkingTime(int walking_time_f[SIZE][SIZE], int count_loop, int method_length_f[SIZE][SIZE])
{
	;
}
//ed:不搞了。。。