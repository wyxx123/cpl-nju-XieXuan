//
// Created by xiexu on 2022/12/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef enum direction
{
	Prev = 0,
	Next = 1,
} Direction;

typedef struct node
{
	struct node* prev;
	struct node* next;
	int val;
} Node;

typedef struct stack
{
	Node* top;
	Node* bottom;
	int size;
} Stack;

void InitialStackArray(int size);
void InitialStack(int index);
void Pour(int source_index, int destination_index);
Direction FindNullDirection(const Node* node);
bool IsStackEmpty(const Stack* stack);
void PrintStackArray(int size);
void PrintStack(const Stack* stack);
void FreeStackArray(int size);
void FreeStack(Stack* stack);

Stack* stack_array = NULL;

int main(void)
{
	int n = 0;
	int m = 0;
	scanf("%d%d", &n, &m);

	stack_array = malloc(n * sizeof(*stack_array));

	InitialStackArray(n);

	for (int i = 0; i < m; i++)
	{
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);

		Pour(x - 1, y - 1);
	}

	PrintStackArray(n);
	FreeStackArray(n);
	return 0;
}

void InitialStackArray(int size)
{
	for (int i = 0; i < size; i++)
	{
		InitialStack(i);
		(stack_array[i]).size = 1;
	}
}

void InitialStack(int index)
{
	Node* node = calloc(1, sizeof(*node));
	node->prev = NULL;
	node->next = NULL;
	node->val = index + 1;

	stack_array[index].top = stack_array[index].bottom = node;
}

void Pour(int source_index, int destination_index)
{
	Stack* source = &stack_array[source_index];
	Stack* destination = &stack_array[destination_index];

	if (IsStackEmpty(source))
		return;

	if (IsStackEmpty(destination))
	{
		destination->top = source->bottom;
		destination->bottom = source->top;
		source->top = source->bottom = NULL;
		destination->size = source->size;
		source->size = 0;
		return;
	}

	Direction source_tmp = FindNullDirection(source->top);
	Direction destination_tmp = FindNullDirection(destination->top);

	if (source_tmp == Prev)
		source->top->prev = destination->top;
	else
		source->top->next = destination->top;

	if (destination_tmp == Prev)
		destination->top->prev = source->top;
	else
		destination->top->next = source->top;

	destination->size += source->size;
	source->size = 0;

	destination->top = source->bottom;
	source->top = source->bottom = NULL;
}

Direction FindNullDirection(const Node* node)
{
	assert(node->next == NULL || node->prev == NULL);
	return (node->next == NULL) ? Next : Prev;
}

bool IsStackEmpty(const Stack* stack)
{
	return (stack->size == 0);
}

void PrintStackArray(int size)
{
	for (int i = 0; i < size; i++)
	{
		PrintStack(&stack_array[i]);
	}
}

void PrintStack(const Stack* stack)
{
	if (IsStackEmpty(stack))
		printf("0\n");
	else
	{
		const Node* prev_node = NULL;
		const Node* cur_node = stack->bottom;
		for (int i = 0; i < stack->size; i++)
		{
			printf("%d ", cur_node->val);

			const Node* tmp_node = (cur_node->next == prev_node) ? cur_node->prev : cur_node->next;
			prev_node = cur_node;
			cur_node = tmp_node;
		}
		printf("\n");
	}
}

void FreeStackArray(int size)
{
	for (int i = 0; i < size; i++)
	{
		FreeStack(&stack_array[i]);
	}
}

void FreeStack(Stack* stack)
{
	if (IsStackEmpty(stack))
	{
		return;
	}

	Node* prev_node = NULL;
	Node* cur_node = stack->bottom;
	for (int i = 0; i < stack->size; i++)
	{
		Node* tmp_node = (cur_node->next == prev_node) ? cur_node->prev : cur_node->next;
		prev_node = cur_node;
		cur_node = tmp_node;
		free(prev_node);
	}
}




