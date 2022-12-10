//
// Created by xiexu on 2022/11/11.
//

/*

  +-+
 / /|
+-+ +
| |/
+-+





length	width	height
6 		2		 4

 row: (4 + 2) * 2 + 1
 --

||||+-+-+-+-+-+-+  (6 + 2)*2 + 1  len_of_array  40*2+1 == 81
   / / / / / / /|
  +-+-+-+-+-+-+ +
 / / / / / / /|/|
+-+-+-+-+-+-+ + +
| | | | | | |/|/|
+-+-+-+-+-+-+ + +
| | | | | | |/|/|
+-+-+-+-+-+-+ + +
| | | | | | |/|/
+-+-+-+-+-+-+ +
| | | | | | |/
+-+-+-+-+-+-+

 */


#include <stdio.h>
#include <string.h>

void set_board(int length, int width, int height);
void print_board(int length, int width, int height);

char board[90][90] = { 0 };

int main(void)
{
	int num_of_cubic = 0;
	int array_of_length[50] = { 0 };
	int array_of_width[50] = { 0 };
	int array_of_height[50] = { 0 };

	scanf("%d", &num_of_cubic);
	for (int i = 0; i < num_of_cubic; i++)
	{
		for (int j = 0; j < 90; j++)
		{
			memset(board[j], ' ', 90);
		}

		scanf("%d", array_of_length + i);
		scanf("%d", array_of_width + i);
		scanf("%d", array_of_height + i);
		set_board(array_of_length[i], array_of_width[i], array_of_height[i]);
		print_board(array_of_length[i], array_of_width[i], array_of_height[i]);
	}

	return 0;
}

//6 2 4
void set_board(int length, int width, int height)
{
	for (int i = 0; i < 2 * width + 1; i += 2)
	{
		for (int j = 2 * width - i; j <= 2 * (width + length) - i; j += 2)
		{
			board[i][j] = '+';
			if (i != 2 * width)
			{
				board[i + 1][j - 1] = '/';
			}
			if (j != 2 * (width + length) - i)
			{
				board[i][j + 1] = '-';
			}
		}
	}

	for (int i = 2 * width + 1; i < 2 * (width + height) + 1; i += 2)
	{
		for (int j = 0; j <= 2 * length; j += 2)
		{
			board[i][j] = '|';
			board[i + 1][j] = '+';
			if (j != 2 * length)
			{
				board[i + 1][j + 1] = '-';
			}
		}

		for (int bias = 0; bias <= 2 * width; bias += 2)
		{
			int bases_j = 2 * length;
			board[i - bias][bases_j + bias] = '|';
			board[i - bias + 1][bases_j + bias] = '+';
			if (bias != 2 * width)
			{
				board[i - bias][bases_j + bias + 1] = '/';
			}
		}
	}
}

void print_board(int length, int width, int height)
{
	for (int i = 0; i <= 2 * (height + width); i++)
	{
		for (int j = 0; j <= 2 * (length + width); j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

//利用了oj的一些特性吧。。。实际上应该不算过的。

//board 大法好，不用考虑顺序了~



































//#include <stdio.h>
//#include <string.h>
//
//void print_cubic(int length, int width, int height, char* this_turn_a_s_row, char* this_turn_l_r_row, int left_time);
//
//int main(void)
//{
//	int num_of_cubic = 0;
//	int array_of_length[50] = { 0 };
//	int array_of_width[50] = { 0 };
//	int array_of_height[50] = { 0 };
//	char this_turn_a_s_row[90] = { 0 };
//	char this_turn_l_r_row[90] = { 0 };
//
//	memset(this_turn_l_r_row, ' ', 89);
//	memset(this_turn_a_s_row, ' ', 89);
//
//	scanf("%d", &num_of_cubic);
//	for (int i = 0; i < num_of_cubic; i++)
//	{
//		scanf("%d", array_of_length + i);
//		scanf("%d", array_of_width + i);
//		scanf("%d", array_of_height + i);
//		print_cubic(array_of_length[i], array_of_width[i], array_of_height[i],
//			this_turn_a_s_row, this_turn_l_r_row, array_of_width[i]);
//	}
//
//	return 0;
//}
//
//void print_cubic(int length, int width, int height, char* this_turn_a_s_row, char* this_turn_l_r_row, int left_time)
//{
//	if (left_time == width)
//	{
//		for (int i = width * 2; i < 2 * (length + width) + 1; i += 2)
//		{
//			this_turn_a_s_row[i] = '+';
//			this_turn_a_s_row[i + 1] = '-';
//		}
//		for (int i = width * 2 - 1; i < 2 * (length + width); i += 2)
//		{
//			this_turn_l_r_row[i] = '/';
//		}
//		this_turn_l_r_row[2 * (length + width)] = '|';
//	}
//	else if (left_time != 0)
//	{
//		int passed_times = width - left_time;
//		this_turn_a_s_row[2 * (width - passed_times)] = '+';
//		this_turn_a_s_row[2 * (width - passed_times) + 1] = '-';
//		this_turn_l_r_row[2 * (length + width - passed_times) + 1] = ' ';
//
//		this_turn_l_r_row[2 * (width - passed_times) - 1] = '/';
//		this_turn_l_r_row[2 * (length + width - passed_times)] = '|';
//	}
//	else
//	{
//		final_print(length,width,)
//	}
//
//}
