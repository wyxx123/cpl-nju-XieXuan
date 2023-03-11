//
// Created by xiexu on 2022/11/13.
//
//#include <stdio.h>
//#include <string.h>
//
//char stack[200000] = { 0 };
//
//void JudgeWhetherBalanced(void);
//
//int main(void)
//{
//	int num_of_input = 0;
//	scanf("%d", &num_of_input);
//	getchar();
//
//	for (int i = 0; i < num_of_input; i++)
//	{
//		JudgeWhetherBalanced();
//	}
//
//	return 0;
//}
//
//void JudgeWhetherBalanced(void)
//{
//	memset(stack, 0, 200000);
//	const char* bottom_of_stack = stack;
//	char* top_of_stack = stack;
//	char tmp_input_char = 0;
//	do
//	{
//		scanf("%c", &tmp_input_char);
//		if (tmp_input_char == ' ');
//		else if ((top_of_stack != bottom_of_stack)
//			&& (((tmp_input_char == ')') && (*(top_of_stack - 1) == '('))
//				|| ((tmp_input_char == ']') && (*(top_of_stack - 1) == '['))
//				|| ((tmp_input_char == '}') && (*(top_of_stack - 1) == '{'))))
//		{
//			top_of_stack--;
//		}
//		else if (tmp_input_char != '\n')
//		{
//			*top_of_stack = tmp_input_char;
//			top_of_stack++;
//		}
//	} while (tmp_input_char != '\n');
//
//	if (top_of_stack == bottom_of_stack)
//		printf("True\n");
//	else
//		printf("False\n");
//}

// tnnd 我就少加了个0...


//NEW：每一遍封装函数：

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 101000

char input_each_term[MAX_SIZE] = { 0 };
char stack[MAX_SIZE] = { 0 };
int top = 0;

bool JudgeAnswer(void);
void PushStack(char ch);

int main(void)
{
	int times = 0;
	scanf("%d", &times);

	for (int i = 0; i < times; i++)
	{
		memset(stack, 0, MAX_SIZE);
		memset(input_each_term, 0, MAX_SIZE);
		top = 0;

		scanf("%101000s", input_each_term);
		bool answer_each_term = JudgeAnswer();

		if (answer_each_term == true)
			printf("True\n");
		else
			printf("False\n");
	}

	return 0;
}

bool JudgeAnswer(void)
{
	int size = (int)strlen(input_each_term);

	for (int i = 0; i < size; i++)
	{
		if (input_each_term[i] == '(' || input_each_term[i] == '[' || input_each_term[i] == '{')
			PushStack(input_each_term[i]);
		else if (top != 0 && ((stack[top - 1] == '(' && input_each_term[i] == ')')
			|| (stack[top - 1] == '[' && input_each_term[i] == ']')
			|| (stack[top - 1] == '{' && input_each_term[i] == '}')))
			top--;
		else
			return false;
	}

	if (top != 0)
		return false;
	return true;
}

void PushStack(char ch)
{
	stack[top] = ch;
	top++;
}

