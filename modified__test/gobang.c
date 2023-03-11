//
// Created by xiexu on 2022/12/10.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_WIDTH 20

char board[BOARD_WIDTH][BOARD_WIDTH] = { 0 };

typedef enum result
{
	Win,
	Lose,
	Not_sure,
} Result;

Result JudgeResult(void);
Result JudgeStatus(char input_board[][BOARD_WIDTH]);
bool InBoard(int i, int j);
bool JudgeNotTie(int i, int j, char input_board[][BOARD_WIDTH], int signal_i, int signal_j);
Result GoOnGame(char term_board[][BOARD_WIDTH]);

int signal_i_array[4] = { 1, 0, 1, 1 };
int signal_j_array[4] = { 0, 1, -1, 1 };

int main(void)
{
	int T = 0;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			scanf("%20s", board[j]);
		}

		Result term_result = JudgeResult();
		if (term_result == Win)
			printf("Win\n");
		else if (term_result == Lose)
			printf("Lose\n");
		else
			printf("Not Sure\n");
	}

	return 0;
}

Result JudgeResult(void)
{
	bool is_win = true;

	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			if (board[i][j] == '_')
			{
				char term_board[BOARD_WIDTH][BOARD_WIDTH] = { 0 };
				strncpy((char*)term_board, (char*)board, BOARD_WIDTH * BOARD_WIDTH);
				term_board[i][j] = '*';

				Result term_status = JudgeStatus(term_board);
				if (term_status == Lose)
					return Lose;

				term_status = GoOnGame(term_board);

				if (term_status != Win)
					is_win = false;
			}
		}
	}

	if (is_win == true)
		return Win;
	return Not_sure;
}

Result JudgeStatus(char input_board[BOARD_WIDTH][BOARD_WIDTH])
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			if (input_board[i][j] != '_')
			{
				bool not_tie = false;
				for (int k = 0; k < 4; k++)
				{
					not_tie |= JudgeNotTie(i, j, input_board, signal_i_array[k], signal_j_array[k]);
				}

				if (not_tie)
					return ((input_board[i][j] == '#') ? Win : Lose);
			}
		}
	}

	return Not_sure;
}

bool InBoard(int i, int j)
{
	return (i >= 0 && i < BOARD_WIDTH && j >= 0 && j < BOARD_WIDTH);
}


bool JudgeNotTie(int i, int j, char input_board[][BOARD_WIDTH], int signal_i, int signal_j)
{
	char judged_side = input_board[i][j];

	for (int k = 0; k < 5; k++)
	{
		if (!InBoard(i + signal_i * k, j + signal_j * k)
			|| input_board[i + signal_i * k][j + signal_j * k] != judged_side)
			return false;
	}
	return true;
}

Result GoOnGame(char term_board[BOARD_WIDTH][BOARD_WIDTH])
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			if (term_board[i][j] == '_')
			{
				char term_term_board[BOARD_WIDTH][BOARD_WIDTH] = { 0 };
				strncpy((char*)term_term_board, (char*)term_board, BOARD_WIDTH * BOARD_WIDTH);
				term_term_board[i][j] = '#';

				Result term_status = JudgeStatus(term_term_board);
				if (term_status == Win)
					return Win;
			}
		}
	}
	return Not_sure;
}
