//
// Created by xiexu on 2022/11/13.
//

/*

| a |
| n |
| t |
|===|

 */


#include <stdio.h>
#include <string.h>

char stack[2000] = { 0 };

void print_operation(const char* top_of_stack, const char* bottom_of_stack);

int main(void)
{
	int num_of_operation = 0;
	char operation_input[10] = { 0 };
	char input_char = 0;

	scanf("%d", &num_of_operation);

	char* top_of_stack = stack;
	const char* bottom_of_stack = stack;
	for (int i = 0; i < num_of_operation; i++)
	{
		scanf("%5s", operation_input);
		if (strcmp(operation_input, "pop") == 0)
		{
			if (top_of_stack == bottom_of_stack)
				printf("Empty\n");
			else
				top_of_stack--;
		}
		if (strcmp(operation_input, "push") == 0)
		{
			scanf(" %c", &input_char);
			*top_of_stack = input_char;
			top_of_stack++;
		}
		if (strcmp(operation_input, "top") == 0)
		{
			if (top_of_stack == bottom_of_stack)
				printf("Empty\n");
			else
				printf("%c\n", *(top_of_stack - 1));
		}
		if (strcmp(operation_input, "print") == 0)
		{
			print_operation(top_of_stack, bottom_of_stack);
		}
		memset(operation_input, 0, 10);
	}

	return 0;
}

void print_operation(const char* top_of_stack, const char* bottom_of_stack)
{
	int print_time = (int)(top_of_stack - bottom_of_stack);
	if (print_time == 0)
		printf("Empty\n");
	else
	{
		for (int i = print_time - 1; i >= 0; i--)
		{
			printf("| %c |\n", stack[i]);
		}
		printf("|===|\n");
	}
}
