//
// Created by xiexu on 2023/2/19.
//
#include <stdio.h>
#include <stdbool.h>

#define N 20

const int RowArray[5][2] = {{ 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }};
const int LineArray[5][2] = {{ 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }};
const int LUArray[5][2] = {{ 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }};
const int LDArray[5][2] = {{ 0, 0, }, { 1, -1 }, { 2, -2 }, { 3, -3 }, { 4, -4 }};

char board[N][N] = { 0 };

int CountWillWin(char input);
bool Suit(char input, int i, int j, const int(* JudgeArray)[2]);

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < N; i++)
		{
			scanf("%20s", board[i]);
		}

		if (CountWillWin('*') != 0)
			printf("Lose\n");
		else if (CountWillWin('#') >= 2)
			printf("Win\n");
		else
			printf("Not Sure\n");
	}
	return 0;
}

int CountWillWin(char input)
{
	int count = 0;
	// row

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= 15; j++)
		{
			if (Suit(input, i, j, RowArray))
				count++;
		}
	}
	// line

	for (int i = 0; i <= 15; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Suit(input, i, j, LineArray))
				count++;
		}
	}

	// '/'

	for (int i = 0; i <= 15; i++)
	{
		for (int j = 0; j <= 15; j++)
		{
			if (Suit(input, i, j, LUArray))
				count++;
		}
	}

	// '\'
	for (int i = 0; i <= 15; i++)
	{
		for (int j = 4; j < N; j++)
		{
			if (Suit(input, i, j, LDArray))
				count++;
		}
	}

	return count;
}

bool Suit(char input, int i, int j, const int(* JudgeArray)[2])
{
	int suit_count = 0;
	int reverse_count = 0;
	int null_count = 0;
	for (int k = 0; k < 5; k++)
	{
		char cur = board[i + JudgeArray[k][0]][j + JudgeArray[k][1]];
		if (cur == input)
			suit_count++;
		else if (cur == '_')
			null_count++;
		else
			reverse_count++;
	}
	if (null_count == 1 && suit_count == 4)
		return true;
	return false;
}
