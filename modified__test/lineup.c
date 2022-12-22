//
// Created by xiexu on 2022/12/21.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct child
{
	int sequence;
	struct child* right_next;
	struct child* down_next;
} Child;
Child start_child = { 0 };

typedef struct children
{
	Child* start_child;
} Children;
Children queue = { .start_child = &start_child };

int m = 0;
int n = 0;

void InitialLinkedList(void);

int main(void)
{
	int q = 0;
	scanf("%d%d%d", &n, &m, &q);

	InitialLinkedList();

	return 0;
}

void InitialLinkedList(void)
{
	Child* row_pointer = queue.start_child;
	Child* pre_row_pointer = NULL;

	for (int i = 0; i <= n; i++
		, pre_row_pointer = (i == 1) ? row_pointer : pre_row_pointer->down_next
		, row_pointer = row_pointer->down_next
		)
	{

		Child* col_pointer = row_pointer;
		Child* pre_col_pointer = NULL;

		for (int j = 0; j <= m; j++
			, pre_col_pointer = (j == 1) ? col_pointer : pre_col_pointer->right_next
			, col_pointer = col_pointer->right_next
			, pre_row_pointer = (i == 0) ? NULL : pre_row_pointer->right_next
			)
		{
			Child* now_child = NULL;
			if (i != 0 || j != 0)
				now_child = malloc(sizeof *now_child);
			else
				now_child = queue.start_child;
		}
	}
}
