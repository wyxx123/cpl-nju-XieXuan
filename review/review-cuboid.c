//
// Created by xiexu on 2023/2/26.
//
#include <stdio.h>

#define MAX_HEIGHT 1024
#define MAX_WIDTH 100
#define MAX_BARRIER_SIZE 200

char board[MAX_HEIGHT][MAX_WIDTH] = { 0 };
char input[MAX_HEIGHT] = { 0 };
int barrier[MAX_BARRIER_SIZE] = { 0 };
int DrawCol(char target, int cur_col);
void DrawEmptyCol(int cur_col);

int char_line = 0;

int main(void)
{
	int len = 0;
	scanf("%d%1024s", &len, input);

	for (int i = 0; i < len; i++)
	{
		barrier[input[i]]++;
	}

	// * find max height
	int max_height = 0;
	for (int i = 0; i < MAX_BARRIER_SIZE; i++)
	{
		max_height = (max_height < barrier[i]) ? barrier[i] : max_height;
	}

	char_line = max_height + 1;
	int cur_col = 0;
	for (int i = 0; i < 26; i++)
	{
		if (DrawCol((char)('a' + i), cur_col))
			cur_col++;
		if (DrawCol((char)('A' + i), cur_col))
			cur_col++;

		if (barrier['a' + i] != 0 || barrier['A' + i] != 0)
		{
			DrawEmptyCol(cur_col);
			cur_col++;
		}
	}

	// * print
	for (int i = 0; i <= char_line; i++)
	{
		for (int j = 0; j < cur_col - 1; j++)
		{
			printf("%c", (board[i][j] == 0) ? ' ' : board[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int DrawCol(char target, int cur_col)
{
	if (barrier[target] == 0)
		return 0;

	board[char_line][cur_col] = target;
	board[char_line - 1][cur_col] = '-';
	for (int i = 1; i <= barrier[target]; i++)
	{
		board[char_line - 1 - i][cur_col] = '=';
	}
	return 1;
}

void DrawEmptyCol(int cur_col)
{
	board[char_line - 1][cur_col] = '-';
}

//