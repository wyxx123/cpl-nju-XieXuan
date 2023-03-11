//
// Created by xiexu on 2023/2/18.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node* next;
	struct node* prev;
} Node;

typedef struct line
{
	Node* top;
	Node* bottom;
} Line;

Line* line_array;

int main(void)
{
	int height = 0;
	int width = 0;
	int op_time = 0;
	scanf("%d%d%d", &height, &width, &op_time);

	line_array = malloc((width + 1) * sizeof(Line));
	int* size_array = malloc((width + 1) * sizeof(int));
	for (int i = 1; i <= width; i++)
	{
		size_array[i] = height;
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			int input = 0;
			scanf("%d", &input);

			Node* cur = malloc(sizeof(*cur));

			cur->num = input;
			if (i == 0)
			{
				cur->next = NULL;
				cur->prev = NULL;
				(line_array[j]).top = (line_array[j]).bottom = cur;
			}
			else
			{
				cur->next = (line_array[j]).bottom;
				(line_array[j]).bottom->prev = cur;
				cur->prev = NULL;
				(line_array[j]).bottom = cur;
			}
		}
	}
	for (int i = 0; i < op_time; i++)
	{
		int source_line = 0;
		int dest_line = 0;

		scanf("%d%d", &source_line, &dest_line);

		(line_array[dest_line]).top->next = (line_array[source_line]).bottom; //? !
		(line_array[source_line]).bottom->prev = (line_array[dest_line]).top;
		(line_array[dest_line]).top = (line_array[dest_line]).top->next;
		(line_array[source_line]).bottom = (line_array[source_line]).bottom->next;
		(line_array[dest_line]).top->next = NULL;
		(line_array[source_line]).bottom->prev = NULL;

		size_array[source_line]--;
		size_array[dest_line]++;
	}

	int max = 0;
	for (int i = 1; i <= width; i++)
	{
		max = ((max >= size_array[i]) ? max : size_array[i]);
	}

	Node** print_array = malloc((width + 1) * sizeof(Node*));
	int cur_print_height = max;
	for (int i = 1; i <= width; i++)
	{
		print_array[i] = NULL;
	}

	for (; cur_print_height >= 1; cur_print_height--)
	{
		for (int i = 1; i <= width; i++)
		{
			if (print_array[i] != NULL)
				print_array[i] = (print_array[i])->prev;
			else if (cur_print_height <= size_array[i])
				print_array[i] = (line_array[i]).top;

			if (print_array[i] != NULL)
				printf("%5d", (print_array[i])->num);
			else
				printf("     ");
		}
		printf("\n");
	}

	free(size_array);
	free(print_array);
//	for (int i = 1; i <= width; i++)
//	{
//		Node* cur = (line_array[i]).bottom;
//		while (cur->next != NULL)
//		{
//			cur = cur->next;
//			free(cur->prev);
//		}
//		free(cur);
//	}
	free(line_array);

	return 0;
}