//
// Created by xiexu on 2022/12/6.
//
#include <stdio.h>

#define SIZE 100010

int chessboard[SIZE];
int arrive[SIZE];

int main(void)
{
	int n;
	int pos;  // 游戏棋子的位置
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &chessboard[i]);
		if (chessboard[i] == 2)
			pos = i;
	}
	arrive[pos] = 1;
	int p = pos;
	// 向左跳
	if (pos > 1)
	{
		if (chessboard[pos - 1] == 0)
		{
			arrive[pos - 1] = 1;
		}
		else
		{
			while (p - 2 >= 1 && chessboard[p - 1] == 1 &&
				chessboard[p - 2] == 0)
			{
				arrive[p - 2] = 1;
				p -= 2;
			}
		}
	}
	// 向右跳
	p = pos;
	if (pos < n)
	{
		if (chessboard[pos + 1] == 0)
		{
			arrive[pos + 1] = 1;
		}
		else
		{
			while (p + 2 <= n && chessboard[p + 1] == 1 &&
				chessboard[p + 2] == 0)
			{
				arrive[p + 2] = 1;
				p += 2;
			}
		}
		return 0;
	}
}