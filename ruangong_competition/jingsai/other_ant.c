//
// Created by xiexu on 2022/12/5.
//
//
// Created by xiexu on 2022/12/4.
//

//k表示将（帅）, e表示象（相），b表示士（仕），||h表示马，c表示车，g表示炮，s表示兵，
//C_move, a_move, judge_unsafe
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define S_MOVEMENT_MAX 3
#define H_MOVEMENT_MAX 8
#define K_MOVEMENT_MAX 4
#define SIZE_OF_BOARD 45
#define E_MOVEMENT_MAX 4

char board[5][9] = { 0 };
int s_vector[S_MOVEMENT_MAX][2] = {{ -1, 0 }, { 0, 1 }, { 0, -1 }};
int h_vector[H_MOVEMENT_MAX][2] =
	{{ -2, 1 }, { -2, -1 }, { 2, 1 }, { 2, -1 }, { -1, 2 }, { -1, -2 }, { 1, 2 }, { 1, -2 }};
int reversed_judge_unmovable_h_vector[H_MOVEMENT_MAX][2] =
	{{ -1, 1 }, { -1, -1 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 }, { 1, 1 }, { 1, -1 }};
int judge_unmovable_h_vector[H_MOVEMENT_MAX][2] =
	{{ -1, 0 }, { -1, 0 }, { 1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 }, { 0, 1 }, { 0, -1 }};
int k_vector[K_MOVEMENT_MAX][2] = {{ -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 0 }};
int e_vector[E_MOVEMENT_MAX][2] = {{ -2, -2 }, { -2, 2 }, { 2, -2 }, { 2, 2 }};


//reversed_judge_unmovable_h_vector
//judge_unmovable_h_vector

bool AntMove(char type_of_move, int i, int j);
bool NotOutOfBoard(int i, int j);
bool AntMoveJudgeIsWin(char moved_board[5][9]);
bool JudgeCIsSafe(char moved_board[5][9]);
bool CMove(char moved_board[5][9]);
bool CMoveType(int i, int j, char type, char moved_board[5][9]);

int main(void)
{
	int num_of_input = 0;
	scanf("%d", &num_of_input);
	bool is_c_win_answer = true;

	for (int i = 0; i < num_of_input; i++)
	{
		int num_of_king = 0;

		is_c_win_answer = true;
		for (int q = 0; q < 5; q++)
		{
			scanf("%9s", (char*)(board + q));
		}

		//default:
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				if (board[j][k] == 'k')
					num_of_king++;
			}
		}


		//ant's term
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				if (board[j][k] == 'h' || board[j][k] == 'c'
					|| board[j][k] == 'g' || board[j][k] == 's')
				{
					bool is_c_win_this_condition = AntMove(board[j][k], j, k);
					if (is_c_win_this_condition == false)
					{
						is_c_win_answer = false;
						break;
					}
				}
			}
			if (is_c_win_answer == false)
				break;
		}


		//default:
		if (num_of_king != 1)
		{
			printf("YES\n");
			continue;
		}

		//print
		if (is_c_win_answer == false)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}


//k表示将（帅）, e表示象（相），b表示士（仕），||h表示马，c表示车，g表示炮，s表示兵，
bool AntMove(char type_of_move, int i, int j)
{
	char moved_board[5][9] = { 0 };
	bool is_ant_win = false;

	if (type_of_move == 's')
	{
		for (int k = 0; k < S_MOVEMENT_MAX; k++)
		{
			strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

			int new_i = i + s_vector[k][0];
			int new_j = j + s_vector[k][1];

			if (NotOutOfBoard(new_i, new_j) == false
				|| board[new_i][new_j] == 'h' || board[new_i][new_j] == 'c'
				|| board[new_i][new_j] == 'g' || board[new_i][new_j] == 's')
				continue;

			moved_board[i][j] = '#';
			moved_board[new_i][new_j] = 's';
			is_ant_win = AntMoveJudgeIsWin(moved_board);

			if (is_ant_win == true)
				break;
		}
	}

	if (type_of_move == 'h')
	{
		for (int k = 0; k < H_MOVEMENT_MAX; k++)
		{
			strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);
			int new_i = i + h_vector[k][0];
			int new_j = j + h_vector[k][1];

			int i_unmovable = i + judge_unmovable_h_vector[k][0];
			int j_unmovable = j + judge_unmovable_h_vector[k][1];

			if (NotOutOfBoard(new_i, new_j) == false
				|| board[new_i][new_j] == 'h' || board[new_i][new_j] == 'c'
				|| board[new_i][new_j] == 'g' || board[new_i][new_j] == 's'
				|| board[i_unmovable][j_unmovable] != '#')
				continue;

			moved_board[i][j] = '#';
			moved_board[new_i][new_j] = 'h';
			is_ant_win = AntMoveJudgeIsWin(moved_board);

			if (is_ant_win == true)
				break;
		}
	}

	if (type_of_move == 'g')
	{
		for (int k = 1; i + k <= 4 && board[i + k][j] == '#'; k++)
		{
			strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

			moved_board[i][j] = '#';
			moved_board[i + k][j] = 'g';
			is_ant_win = AntMoveJudgeIsWin(moved_board);

			if (is_ant_win == true)
				break;
		}

		if (is_ant_win == false)
			for (int k = 1; i - k >= 0 && board[i - k][j] == '#'; k++)
			{
				strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

				moved_board[i][j] = '#';
				moved_board[i - k][j] = 'g';

				is_ant_win = AntMoveJudgeIsWin(moved_board);

				if (is_ant_win == true)
					break;
			}

		if (is_ant_win == false)
			for (int k = 1; j + k <= 8 && board[i][j + k] == '#'; k++)
			{
				strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

				moved_board[i][j] = '#';
				moved_board[i][j + k] = 'g';

				is_ant_win = AntMoveJudgeIsWin(moved_board);

				if (is_ant_win == true)
					break;
			}

		if (is_ant_win == false)
			for (int k = 1; j - k >= 0 && board[i][j - k] == '#'; k++)
			{
				strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

				moved_board[i][j] = '#';
				moved_board[i][j - k] = 'g';

				is_ant_win = AntMoveJudgeIsWin(moved_board);

				if (is_ant_win == true)
					break;
			}
	}

	if (type_of_move == 'c')
	{
		int k = 1;
		for (k = 1; i + k <= 4 && board[i + k][j] == '#'; k++)
		{
			strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

			moved_board[i][j] = '#';
			moved_board[i + k][j] = 'c';

			is_ant_win = AntMoveJudgeIsWin(moved_board);

			if (is_ant_win == true)
				break;
		}

		if (is_ant_win == false)
		{
			if (k + i <= 4
				&& board[k + i][j] != 'c'
				&& board[k + i][j] != 'h'
				&& board[k + i][j] != 'g'
				&& board[k + i][j] != 's')
			{
				strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

				moved_board[i][j] = '#';
				moved_board[i + k][j] = 'c';

				is_ant_win = AntMoveJudgeIsWin(moved_board);
			}

			if (is_ant_win == false)
				for (k = 1; i - k >= 0 && board[i - k][j] == '#'; k++)
				{
					strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

					moved_board[i][j] = '#';
					moved_board[i - k][j] = 'c';

					is_ant_win = AntMoveJudgeIsWin(moved_board);

					if (is_ant_win == true)
						break;
				}
		}

		if (is_ant_win == false)
		{
			if (i - k >= 0
				&& board[i - k][j] != 'c'
				&& board[i - k][j] != 'h'
				&& board[i - k][j] != 'g'
				&& board[i - k][j] != 's')
			{
				strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

				moved_board[i][j] = '#';
				moved_board[i - k][j] = 'c';

				is_ant_win = AntMoveJudgeIsWin(moved_board);
			}

			if (is_ant_win == false)
				for (k = 1; j + k <= 8 && board[i][j + k] == '#'; k++)
				{
					strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

					moved_board[i][j] = '#';
					moved_board[i][j + k] = 'c';

					is_ant_win = AntMoveJudgeIsWin(moved_board);

					if (is_ant_win == true)
						break;
				}
		}

		if (is_ant_win == false)
		{
			if (j + k <= 8
				&& board[i][j + k] != 'c'
				&& board[i][j + k] != 'h'
				&& board[i][j + k] != 'g'
				&& board[i][j + k] != 's')
			{
				strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

				moved_board[i][j] = '#';
				moved_board[i][j + k] = 'c';

				is_ant_win = AntMoveJudgeIsWin(moved_board);

			}

			if (is_ant_win == false)
				for (k = 1; j - k >= 0 && board[i][j - k] == '#'; k++)
				{
					strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

					moved_board[i][j] = '#';
					moved_board[i][j - k] = 'c';

					is_ant_win = AntMoveJudgeIsWin(moved_board);

					if (is_ant_win == true)
						break;
				}
		}

		if (is_ant_win == false && j - k >= 0
			&& board[i][j - k] != 'c'
			&& board[i][j - k] != 'h'
			&& board[i][j - k] != 'g'
			&& board[i][j - k] != 's')
		{
			strncpy((char*)moved_board, (char*)board, SIZE_OF_BOARD);

			moved_board[i][j] = '#';
			moved_board[i][j - k] = 'c';

			is_ant_win = AntMoveJudgeIsWin(moved_board);
		}
	}

	return !is_ant_win;
}

bool NotOutOfBoard(int i, int j)
{
	return (i >= 0 && j >= 0 && i <= 4 && j <= 8);
}

/**
 *
 * @param new_i
 * @param new_j
 * @param moved_board
 * @param type
 * @return true if C lose, ant win.
 */
bool AntMoveJudgeIsWin(char moved_board[5][9])
{
	bool is_safe = JudgeCIsSafe(moved_board);
	if (is_safe == false)
	{
		bool is_c_lose = CMove(moved_board);
		return is_c_lose;
	}
	else
		return false;
}


/**
 *
 * @param moved_board
 * @return true if C is safe.
 */
bool JudgeCIsSafe(char moved_board[5][9])
{
	bool is_safe = true;
	int king_i = 0;
	int king_j = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (moved_board[i][j] == 'k')
			{
				king_i = i;
				king_j = j;
				break;
			}
		}
	}

	//s:
	for (int i = 0; i < 3; i++)
	{
		int new_i = king_i - s_vector[i][0];
		int new_j = king_j - s_vector[i][1];

		if (moved_board[new_i][new_j] == 's')
		{
			is_safe = false;
			break;
		}
	}

	//h:
	if (is_safe == true)
	{
		for (int i = 0; i < 8; i++)
		{
			int new_i = king_i + h_vector[i][0];
			int new_j = king_j + h_vector[i][1];

			int judge_i = king_i + reversed_judge_unmovable_h_vector[i][0];
			int judge_j = king_j + reversed_judge_unmovable_h_vector[i][1];

			if (moved_board[new_i][new_j] == 'h' && moved_board[judge_i][judge_j] == '#')
			{
				is_safe = false;
				break;
			}
		}
	}

	//c
	if (is_safe == true)
	{
		int i = 1;
		for (; king_i + i <= 4 && moved_board[king_i + i][king_j] == '#'; i++);
		if (king_i + i <= 4 && moved_board[king_i + i][king_j] == 'c')
			is_safe = false;

		if (is_safe == true)
		{
			for (i = 1; king_i - i >= 0 && moved_board[king_i - i][king_j] == '#'; i++);
			if (king_i + i >= 0 && moved_board[king_i - i][king_j] == 'c')
				is_safe = false;
		}

		if (is_safe == true)
		{
			for (i = 1; king_j + i <= 8 && moved_board[king_i][king_j + i] == '#'; i++);
			if (king_j + i <= 8 && moved_board[king_i][king_j + i] == 'c')
				is_safe = false;
		}

		if (is_safe == true)
		{
			for (i = 1; king_j - i >= 0 && moved_board[king_i][king_j - i] == '#'; i++);
			if (king_j - i >= 0 && moved_board[king_i][king_j - i] == 'c')
				is_safe = false;
		}
	}

	//g
	if (is_safe == true)
	{

		char first__type = 0;
		char second__type = 0;

		for (int i = 1; king_i + i <= 4; i++)
		{
			if (moved_board[king_i + i][king_j] != '#')
			{
				if (first__type == 0)
				{
					first__type = moved_board[king_i + i][king_j];
					continue;
				}
				if (second__type == 0)
					second__type = moved_board[king_i + i][king_j];
			}
		}
		if (second__type == 'g')
			is_safe = false;

		if (is_safe == true)
		{
			first__type = 0;
			second__type = 0;
			for (int i = 1; king_i - i >= 0; i++)
			{
				if (moved_board[king_i - i][king_j] != '#')
				{
					if (first__type == 0)
					{
						first__type = moved_board[king_i - i][king_j];
						continue;
					}
					if (second__type == 0)
						second__type = moved_board[king_i - i][king_j];
				}
			}

			if (second__type == 'g')
				is_safe = false;
		}

		if (is_safe == true)
		{
			first__type = 0;
			second__type = 0;
			for (int i = 1; king_j + i <= 8; i++)
			{

				if (moved_board[king_i][king_j + i] != '#')
				{
					if (first__type == 0)
					{
						first__type = moved_board[king_i][king_j + i];
						continue;
					}
					if (second__type == 0)
						second__type = moved_board[king_i][king_j + i];
				}
			}

			if (second__type == 'g')
				is_safe = false;
		}

		if (is_safe == true)
		{
			first__type = 0;
			second__type = 0;
			for (int i = 1; king_j - i >= 0; i++)
			{

				if (moved_board[king_i][king_j - i] != '#')
				{
					if (first__type == 0)
					{
						first__type = moved_board[king_i][king_j - i];
						continue;
					}
					if (second__type == 0)
						second__type = moved_board[king_i][king_j - i];
				}
			}

			if (second__type == 'g')
				is_safe = false;
		}
	}

	return is_safe;
}


//k表示将（帅）, e表示象（相），b表示士（仕），h表示马，c表示车，g表示炮，s表示兵，规则为中国象棋的规则。
/**
 *
 * @return true: ant win.
 */
bool CMove(char moved_board[5][9])
{
	bool is_ant_win = true;

	for (int i = 0; i < 5; i++)
	{
		if (is_ant_win == false)
			break;

		for (int j = 0; j < 9; j++)
		{
			if (is_ant_win == false)
				break;

			if (moved_board[i][j] == 'k'
				|| moved_board[i][j] == 'e'
				|| moved_board[i][j] == 'b')
			{
				is_ant_win = CMoveType(i, j, moved_board[i][j], moved_board);
			}

		}
	}

	return is_ant_win;
}

/**
 *
 * @param i
 * @param j
 * @param type
 * @param double_moved_board
 * @return true if ant win.
 */
bool CMoveType(int i, int j, char type, char moved_board[5][9])
{
	bool is_ant_win = true;
	char double_moved_board[5][9] = { 0 };

	//k
	if (type == 'k')
		for (int k = 0; k < 4; k++)
		{
			if (is_ant_win == false)
				break;

			int new_i = i + k_vector[k][0];
			int new_j = j + k_vector[k][1];

			if (new_i >= 0 && new_i <= 2 && new_j >= 3 && new_j <= 5
				&& moved_board[new_i][new_j] != 'b'
				&& moved_board[new_i][new_j] != 'e')
			{
				strncpy((char*)double_moved_board, (char*)moved_board, SIZE_OF_BOARD);

				double_moved_board[i][j] = '#';
				double_moved_board[new_i][new_j] = 'k';

				is_ant_win = !(JudgeCIsSafe(double_moved_board));
			}
		}

	//e
	if (type == 'e')
		for (int k = 0; k < 4; k++)
		{
			strncpy((char*)double_moved_board, (char*)moved_board, SIZE_OF_BOARD);

			if (is_ant_win == false)
				break;

			int new_i = i + e_vector[k][0];
			int new_j = j + e_vector[k][1];

			int judge_i = i + e_vector[k][0] / 2;
			int judge_j = j + e_vector[k][1] / 2;

			if (new_i >= 0 && new_i <= 4 && new_j >= 0 && new_j <= 8
				&& double_moved_board[new_i][new_j] != 'k'
				&& double_moved_board[new_i][new_j] != 'e'
				&& double_moved_board[new_i][new_j] != 'b'
				&& double_moved_board[judge_i][judge_j] == '#')
			{
				strncpy((char*)double_moved_board, (char*)moved_board, SIZE_OF_BOARD);

				double_moved_board[i][j] = '#';
				double_moved_board[new_i][new_j] = 'e';

				is_ant_win = !(JudgeCIsSafe(double_moved_board));
			}

		}

	//b
	if (type == 'b')
		for (int k = 0; k < 4; k++)
		{
			if (is_ant_win == false)
				break;

			int new_i = i + e_vector[k][0] / 2;
			int new_j = j + e_vector[k][1] / 2;

			if (new_i >= 0 && new_i <= 2 && new_j >= 3 && new_j <= 5
				&& moved_board[new_i][new_j] != 'b'
				&& moved_board[new_i][new_j] != 'e'
				&& moved_board[new_i][new_j] != 'k')
			{
				strncpy((char*)double_moved_board, (char*)moved_board, SIZE_OF_BOARD);

				double_moved_board[i][j] = '#';
				double_moved_board[new_i][new_j] = 'b';

				is_ant_win = !(JudgeCIsSafe(double_moved_board));
			}
		}

	return is_ant_win;

}







