//
// Created by xiexu on 2022/12/17.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int easy_size;
	int id;
	struct node* next;
} Node;

typedef struct linked_list
{
	Node* head;
} LinkedList;
Node head_node = { 0 };
LinkedList link_List = { .head = &head_node };
LinkedList* linked_list = &link_List;
int list_size = 1;

void Question(void);
void Ask(int input_id, int easy_size);
int FindEasySize(int input_actual_size);
Node* FindEqualNode(int easy_size);
Node* FindBiggerNode(int easy_size);
void AddTheNode(Node* input_node);
void FreeList(void);

int main(void)
{
	int n = 0;
	int q = 0;

	scanf("%d%d", &n, &q);

	linked_list->head->easy_size = n;

	for (int i = 0; i < q; i++)
	{
		char tmp[5] = { 0 };
		scanf("%5s", tmp);

		int input_id = 0;
		int input_actual_size = 0;
		switch (*tmp)
		{
		case 'Q':
			Question();
			break;
		case 'A':
			scanf("%d%d", &input_id, &input_actual_size);
			int easy_size = FindEasySize(input_actual_size);
			Ask(input_id, easy_size);
			break;
		default:
			printf("wy_xx123:err\n");
		}
	}

	FreeList();

	return 0;
}

void Question(void)
{
	printf("%d\n", list_size);

	Node* cur = linked_list->head;
	do
	{
		printf("%d ", cur->id);
		cur = cur->next;
	} while (cur != NULL);

	printf("\n");
}

int FindEasySize(int input_actual_size)
{
	int i = 0;
	for (i = 0; (1 << i) < input_actual_size; i++);

	return i;
}

void Ask(int input_id, int easy_size)
{
	Node* equal_node = FindEqualNode(easy_size);
	if (equal_node != NULL)
	{
		equal_node->id = input_id;
		return;
	}

	list_size++;
	Node* first_bigger_node = FindBiggerNode(easy_size);
	first_bigger_node->easy_size--;
	AddTheNode(first_bigger_node);

	Ask(input_id, easy_size);
}

/**
 * Return NULL if there is no equal size node, or return the pointer to that node.
 * Notice that linked_list can't be an empty linked list.
 * @param easy_size
 * @return
 */
Node* FindEqualNode(int easy_size)
{
	Node* cur = linked_list->head;
	while (cur != NULL && (cur->easy_size != easy_size || cur->id != 0))
		cur = cur->next;

	return cur;
}

/**
 * return pointer to  the first bigger node.
 * Notice that linked_list can't be an empty linked list.
 * @param easy_size
 * @return
 */
Node* FindBiggerNode(int easy_size)
{
	Node* cur = linked_list->head;
	while (cur != NULL && (cur->easy_size < easy_size || cur->id != 0))
		cur = cur->next;

	return cur;
}

void AddTheNode(Node* input_node)
{
	Node* prev = input_node;
	Node* next = input_node->next;

	Node* cur = malloc(sizeof *cur);
	cur->id = 0;
	cur->easy_size = prev->easy_size;
	cur->next = next;

	prev->next = cur;
}

void FreeList(void)
{
	if (linked_list->head->next == NULL)
	{
		free(linked_list->head);
		return;
	}

	Node* cur = linked_list->head->next;
	Node* next = cur->next;

	while (next != NULL)
	{
		free(cur);
		cur = next;
		next = cur->next;
	}
	free(cur);
}