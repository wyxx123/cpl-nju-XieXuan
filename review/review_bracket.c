//
// Created by xiexu on 2023/2/25.
//
#include <stdio.h>
#include <string.h>
#define MAX 200009

void Solve(void);

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		Solve();
	}
	return 0;
}

void Solve(void)
{
	char input[MAX] = { 0 };
	char stack[MAX] = { 0 };
	int top = 0;
	scanf("%s", input);

	int len = strlen(input);
	if (len == 0)
	{
		printf("True\n");
		return;
	}
	for (int i = 0; i < len; i++) // 把strlen写在这里不会被优化。。。
	{
		char in_ch = input[i];

		if ((top != 0) && ((in_ch == ')' && stack[top - 1] == '(')
				|| (in_ch == ']' && stack[top - 1] == '[')
				|| (in_ch == '}' && stack[top - 1] == '{')))
			top--;
		else
		{
			stack[top++] = in_ch;
		}
	}

	if (top != 0)
		printf("False\n");
	else
		printf("True\n");
}

