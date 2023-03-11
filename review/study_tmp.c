//
// Created by xiexu on 2022/12/26.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
} Node;

typedef struct stack
{
	Node* top;
	Node* bottom;
} Stack;

void operate(Stack* p, Stack* q);
void print(Stack* p, int n);

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	Stack* all_stack[n];//记录每一个栈的指针
	Node* temp;
	for (int k = 0; k < n; ++k)
	{
		all_stack[k] = malloc(sizeof(Stack));
		all_stack[k]->top = malloc(sizeof(Node));
		all_stack[k]->bottom = malloc(sizeof(Node));
		temp = malloc(sizeof(Node));
		temp->val = k + 1;
		temp->next = NULL;
		all_stack[k]->top = temp;
		all_stack[k]->bottom = temp;
	}
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		operate(all_stack[x - 1], all_stack[y - 1]);
	}
	for (int j = 0; j < n; ++j)
	{
		print(all_stack[j], n);
	}

	for (int a = 0; a < n; ++a)
	{
		free(all_stack[a]->top);
		free(all_stack[a]->bottom);
		free(all_stack[a]);
	}
}

void operate(Stack* p, Stack* q)
{//p表示倒方，q表示接受方
	if (p->top == NULL)return;
	while (p->top != NULL)
	{
		Node* temp = p->top->next;
		p->top->next = q->top;
		q->top = p->top;
		p->top = temp;
	}
}

void print(Stack* p, int n)
{
	if (p->top == NULL)
	{
		printf("%d\n", 0);
		return;
	}
	int arr[n];
	int count = 0;
	for (; p->top != NULL; ++count)
	{
		arr[count] = p->top->val;
		p->top = p->top->next;
	}
	for (int i = count - 1; i >= 0; --i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}