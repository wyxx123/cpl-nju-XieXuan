//
// Created by xiexu on 2022/12/4.
//
#include <stdio.h>

#define MAX_WIDTH 1000000
#define LEFT 0
#define RIGHT 1

int ans_board[MAX_WIDTH] = { 0 };
int input_board[MAX_WIDTH] = { 0 };
int width = 0;

void JudgeMovable(int now_index, int direction);

int main(void)
{

	scanf("%d", &width);
	for (int i = 0; i < width; i++)
	{
		scanf("%d", input_board + i);
	}

	//judge


	int index_of_me = 0;
	for (int i = 0; i < width; i++)
	{
		if (input_board[i] == 2)
		{
			index_of_me = i;
			break;
		}
	}

	ans_board[index_of_me] = 1;

	if (index_of_me != width - 1)
	{
		if (input_board[index_of_me + 1] == 0)
			ans_board[index_of_me + 1] = 1;

		JudgeMovable(index_of_me, RIGHT);
	}

	if (index_of_me != 0)
	{
		if (input_board[index_of_me - 1] == 0)
			ans_board[index_of_me - 1] = 1;

		JudgeMovable(index_of_me, LEFT);
	}

	//print

	for (int i = 0; i < width; i++)
	{
		printf("%d ", ans_board[i]);
	}

	return 0;
}

void JudgeMovable(int now_index, int direction)
{
	if (direction == RIGHT)
	{
		if (now_index >= width - 2)
			return;
		else if (input_board[now_index + 1] == 1 && input_board[now_index + 2] == 0)
		{
			ans_board[now_index + 2] = 1;
			JudgeMovable(now_index + 2, RIGHT);
		}
	}

	if (direction == LEFT)
	{
		if (now_index <= 1)
			return;
		else if (input_board[now_index - 1] == 1 && input_board[now_index - 2] == 0)
		{
			ans_board[now_index - 2] = 1;
			JudgeMovable(now_index - 2, LEFT);
		}
	}
}
