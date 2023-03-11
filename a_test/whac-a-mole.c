//
// Created by xiexu on 2023/2/25.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 666
int board[MAX][MAX] = { 0 };

#define MAX_ARRAY 1000000
int max = -2147483648;
int max_count = 0;
int max_index_array[MAX_ARRAY][2] = { 0 };

int n = 0;
int m = 0;
int d = 0;

bool InBoard(int x, int y);
int FirstCount(void);
int AddElement(int x, int y, int flag);
int DownCount(int prev_count, int x, int y);
int RightCount(int prev_count, int x, int y);
void ChangeMax(int ret, int x, int y);
int LeftCount(int prev_count, int x, int y);

int main(void)
{

	scanf("%d%d%d", &n, &m, &d);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	int prev_count = FirstCount();
	ChangeMax(prev_count, 1, 1);
	for (int i = 2; i <= m * n; i++)
	{
		int x = (i - 1) / m + 1;
		int tmp_mod = (((i - 1) % m) + 1);
		int y = (x % 2 == 1) ? tmp_mod : (m - tmp_mod + 1);

		int ret = 0;
		if (i % m == 1) // down
		{
			ret = DownCount(prev_count, x, y);
		}
		else //left or right: right 1, left -1
		{
			if (x % 2 == 1)
				ret = RightCount(prev_count, x, y);
			else
				ret = LeftCount(prev_count, x, y);
		}

		ChangeMax(ret, x, y);
		prev_count = ret;
	}

	printf("%d %d\n", max, max_count);
	for (int i = 0; i < max_count; i++)
	{
		printf("%d %d\n", max_index_array[i][0], max_index_array[i][1]);
	}

	return 0;
}

bool InBoard(int x, int y)
{
	return (x >= 1 && x <= n) && (y >= 1 && y <= m);
}

int FirstCount(void)
{
	int count = 0;
	for (int i = 1; i <= d + 1; i++)
	{
		for (int j = 1; j <= d + 2 - i; j++)
		{
			count += board[i][j];
		}
	}
	return count;
}

int DownCount(int prev_count, int x, int y)
{
	int cur_count = prev_count;
	for (int i = x, bias = d; i <= x + d; i++, bias--)
	{

		cur_count += AddElement(i, y + bias, 1);
		if (bias != 0)
			cur_count += AddElement(i, y - bias, 1);
	}

	int prev_x = x - 1;
	for (int i = prev_x, bias = d; i >= prev_x - d; i--, bias--)
	{
		cur_count += AddElement(i, y + bias, -1);
		if (bias != 0)
			cur_count += AddElement(i, y - bias, -1);
	}
	return cur_count;
}

int AddElement(int x, int y, int flag)
{
	if (InBoard(x, y))
		return flag * board[x][y];
	return 0;
}

int RightCount(int prev_count, int x, int y)
{
	int flag = (x % 2 == 1) ? 1 : -1;
	int cur_count = prev_count;
	for (int i = y, bias = d; i <= y + d; i++, bias--)
	{
		cur_count += AddElement(x + bias, i, flag);
		if (bias != 0)
			cur_count += AddElement(x - bias, i, flag);
	}

	int prev_y = y - flag;
	for (int i = prev_y, bias = d; i >= prev_y - d; i--, bias--)
	{
		cur_count -= AddElement(x + bias, i, flag);
		if (bias != 0)
			cur_count -= AddElement(x - bias, i, flag);
	}
	return cur_count;
}

int LeftCount(int prev_count, int x, int y)
{
	int flag = (x % 2 == 1) ? 1 : -1;
	int prev_y = y - flag;
	int cur_count = prev_count;
	for (int i = prev_y, bias = d; i <= prev_y + d; i++, bias--)
	{
		cur_count += AddElement(x + bias, i, flag);
		if (bias != 0)
			cur_count += AddElement(x - bias, i, flag);
	}

	for (int i = y, bias = d; i >= y - d; i--, bias--)
	{
		cur_count -= AddElement(x + bias, i, flag);
		if (bias != 0)
			cur_count -= AddElement(x - bias, i, flag);
	}
	return cur_count;
}

void ChangeMax(int ret, int x, int y)
{
	if (ret > max)
	{
		max = ret;
		memset(max_index_array, 0, sizeof(int) * 2 * max_count);
		max_count = 1;
		max_index_array[0][0] = x;
		max_index_array[0][1] = y;
	}
	else if (ret == max)
	{
		max_index_array[max_count][0] = x;
		max_index_array[max_count][1] = y;
		max_count++;
	}
}


