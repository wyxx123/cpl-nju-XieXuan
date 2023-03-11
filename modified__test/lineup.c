//
// Created by xiexu on 2022/12/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
	int val;
	struct node* r_next;
	struct node* d_next;
} Node;

typedef struct linked_list
{
	Node* head;
} LL;

Node** InitList(LL* list, int n, int m);
long long CountLL(LL* list, int count_row);
Node* GoDown(Node* base, int range);
Node* GoRight(Node* base, int range);
Node* FindNode(Node* base, int x, int y);
void ReversedLL(LL* list, int x1, int y1, int x2, int y2, int x3, int y3);
void ReverseRow(Node* base1, Node* base2, int width);
void ReverseNodeD(Node* n1, Node* n2);
void ReverseCol(Node* base1, Node* base2, int height);
void ReverseNodeR(Node* n1, Node* n2);

void test1(LL* list)
{
	printf("%lld", CountLL(list, 1));
}

int main(void)
{
	LL list = { 0 };

	int n = 0;
	int m = 0;
	scanf("%d%d", &n, &m);

	Node** sequence_array = InitList(&list, n, m);

	int times = 0;
	scanf("%d\n", &times);

	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int x3 = 0;
	int y3 = 0;
	int x4 = 0;
	int y4 = 0;
	int count_row = 0;
	for (int i = 0; i < times; i++)
	{
		scanf("%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &count_row);
		ReversedLL(&list, x1, y1, x2, y2, x3, y3);

		long long test = CountLL(&list, count_row);

		printf("%lld\n", test);
	}

	for (int i = 0; i < (n + 1) * (m + 1); i++)
	{
		free(sequence_array[i]);
	}

	free(sequence_array);
	return 0;
}

/**
 * return sequence array
 * @param list
 * @param n
 * @param m
 * @return
 */
Node** InitList(LL* list, int n, int m)
{
	Node** array = malloc((n + 1) * (m + 1) * sizeof(Node*));

	int count = m + 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			array[i * (m + 1) + j] = malloc(sizeof(Node*));
			if (i >= 1 && j >= 1)
				array[i * (m + 1) + j]->val = count++;
			else
				array[i * (m + 1) + j]->val = 0;
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			array[i * (m + 1) + j]->r_next = (j == m) ? NULL : array[i * (m + 1) + j + 1];
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			array[i * (m + 1) + j]->d_next = (i == n) ? NULL : array[(i + 1) * (m + 1) + j];
		}
	}

	list->head = *array;

	return array;
}

Node* GoDown(Node* base, int range)
{
	for (int i = 0; i < range; i++)
	{
		base = base->d_next;
	}
	return base;
}

Node* GoRight(Node* base, int range)
{
	for (int i = 0; i < range; i++)
	{
		base = base->r_next;
	}
	return base;
}

long long CountLL(LL* list, int count_row)
{
	Node* base = GoRight(GoDown(list->head, count_row), 1);

	long long count = 0;
	while (base != NULL)
	{
		count += base->val;
		base = base->r_next;
	}
	return count;
}

Node* FindNode(Node* base, int x, int y)
{
	return GoRight(GoDown(base, x), y);
}

void ReversedLL(LL* list, int x1, int y1, int x2, int y2, int x3, int y3)
{
	int width = y2 - y1;
	int height = x2 - x1;

	Node* head = list->head;

	Node* base1 = FindNode(head, x1 - 1, y1 - 1);
	Node* base2 = FindNode(head, x3 - 1, y3 - 1);
	Node* row_base1 = GoRight(base1, 1);
	Node* row_base2 = GoRight(base2, 1);
	Node* row_base3 = GoDown(row_base1, height + 1);
	Node* row_base4 = GoDown(row_base2, height + 1);
	Node* col_base1 = GoDown(base1, 1);
	Node* col_base2 = GoDown(base2, 1);
	Node* col_base3 = GoRight(col_base1, width + 1);
	Node* col_base4 = GoRight(col_base2, width + 1);

	ReverseRow(row_base1, row_base2, width);
	ReverseRow(row_base3, row_base4, width);

	ReverseCol(col_base1, col_base2, height);
	ReverseCol(col_base3, col_base4, height);
}

void ReverseRow(Node* base1, Node* base2, int width)
{
	for (int i = 0; i <= width; i++)
	{
		ReverseNodeD(base1, base2);
		base1 = base1->r_next;
		base2 = base2->r_next;
	}
}

void ReverseNodeD(Node* n1, Node* n2)
{
	Node* tmp = n1->d_next;
	n1->d_next = n2->d_next;
	n2->d_next = tmp;
}

void ReverseCol(Node* base1, Node* base2, int height)
{
	for (int i = 0; i <= height; i++)
	{
		ReverseNodeR(base1, base2);
		base1 = base1->d_next;
		base2 = base2->d_next;
	}
}

void ReverseNodeR(Node* n1, Node* n2)
{
	Node* tmp = n1->r_next;
	n1->r_next = n2->r_next;
	n2->r_next = tmp;
}


//4 6 1
//1 1 2 3 3 4 4 6 2
