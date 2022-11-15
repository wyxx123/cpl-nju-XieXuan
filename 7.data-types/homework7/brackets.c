//
// Created by xiexu on 2022/11/13.
//
#include <stdio.h>
#include <string.h>

char stack[200000] = { 0 };

void JudgeWhetherBalanced(void);

int main(void)
{
	int num_of_input = 0;
	scanf("%d", &num_of_input);
	getchar();

	for (int i = 0; i < num_of_input; i++)
	{
		JudgeWhetherBalanced();
	}

	return 0;
}

void JudgeWhetherBalanced(void)
{
	memset(stack, 0, 200000);
	const char* bottom_of_stack = stack;
	char* top_of_stack = stack;
	char tmp_input_char = 0;
	do
	{
		scanf("%c", &tmp_input_char);
		if (tmp_input_char == ' ');
		else if ((top_of_stack != bottom_of_stack)
			&& (((tmp_input_char == ')') && (*(top_of_stack - 1) == '('))
				|| ((tmp_input_char == ']') && (*(top_of_stack - 1) == '['))
				|| ((tmp_input_char == '}') && (*(top_of_stack - 1) == '{'))))
		{
			top_of_stack--;
		}
		else if (tmp_input_char != '\n')
		{
			*top_of_stack = tmp_input_char;
			top_of_stack++;
		}
	} while (tmp_input_char != '\n');

	if (top_of_stack == bottom_of_stack)
		printf("True\n");
	else
		printf("False\n");
}

// tnnd 我就少加了个0...