//
// Created by xiexu on 2022/11/4.
//
/*
 *
 */

//   /\   --2
//  /__\   --4

/*
 *2^n -- 2^(n+1)
 *
 * (2^n-1,0)
 * (0,2^n-1)
 * (2^(n+1)-1,2^n-1)
 *
 *
 */

#include <stdio.h>
#include <math.h>

char board[4096][2048] = { 0 };
void set_board(int n);
void paint(int n, int i_index, int j_index);
void paint_one(int i_index, int j_index);

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	set_board(n);
	paint(n, 0, 0);

	int max_row = (int)pow(2, n);
	int max_col = (int)pow(2, n + 1);
	for (int i = 0; i < max_row; i++)
	{
		for (int j = 0; j < max_col; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void set_board(int n)
{
	int max_row = (int)pow(2, n);
	int max_col = (int)pow(2, n + 1);
	for (int i = 0; i < max_row; i++)
	{
		for (int j = 0; j < max_col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void paint(int n, int i_index, int j_index)
{
	if (n == 1)
	{
		paint_one(i_index, j_index);
		return;
	}

	int tmp_result_of_two_n = (int)pow(2, n - 1);
	paint(n - 1, i_index, j_index + tmp_result_of_two_n);
	paint(n - 1, i_index + tmp_result_of_two_n, j_index);
	paint(n - 1, i_index + tmp_result_of_two_n, j_index + 2 * tmp_result_of_two_n);
}

void paint_one(int i_index, int j_index)
{
	board[i_index + 1][j_index] = '/';
	board[i_index][j_index + 1] = '/';
	board[i_index][j_index + 2] = '\\';
	board[i_index + 1][j_index + 3] = '\\';
	board[i_index + 1][j_index + 1] = '_';
	board[i_index + 1][j_index + 2] = '_';
}


