//
// Created by xiexu on 2022/12/23.
//
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN_COMMENT 15

typedef struct node
{
	int val;
	struct node* prev;
	struct node* next;
} Node;

typedef struct linked_list
{
	Node* head;
	Node* tail;
	int size;
} LinkedList;

void PushBack(LinkedList* list, int val);
void Init(LinkedList* list);
bool IsEmpty(const LinkedList* list);
void DeleteNode(Node* node);

void InitialLoop(LinkedList* list, int size);
void PrintLoop(const Node* cur_node);
void Move(const LinkedList* list, int len, Node** cur_node, Node* (* OneMove)(const Node*));
Node* PrevMove(const Node* cur_node);
Node* NextMove(const Node* cur_node);
void InsertLoop(LinkedList* list, int num_insert, Node* input_node);
Node* RemoveLoop(LinkedList* list, Node* cur_node);
void FreeLoop(LinkedList* list);

int main(void)
{
	int n = 0;
	int T = 0;
	scanf("%d%d", &n, &T);

	LinkedList list = { 0 };
	InitialLoop(&list, n);
	Node* cur_node = list.head;
	list.size = n;

	for (int i = 0; i < T; i++)
	{
		char command[MAX_LEN_COMMENT] = { 0 };
		int num_input = 0;
		scanf("%15s", command);
		switch (*command)
		{
		case 'F':
			scanf("%d", &num_input);
			Move(&list, num_input % list.size, &cur_node, NextMove);
			break;
		case 'B':
			scanf("%d", &num_input);
			Move(&list, num_input % list.size, &cur_node, PrevMove);
			break;
		case 'I':
			scanf("%d", &num_input);
			InsertLoop(&list, num_input, cur_node);
			break;
		case 'R':
			cur_node = RemoveLoop(&list, cur_node);
			break;
		case 'P':
			PrintLoop(cur_node);
			break;
		default:
			assert(0);
		}
	}

	FreeLoop(&list);
	return 0;
}

// ! make sure you don't init linked list that contains something!
void Init(LinkedList* list)
{
	list->head = NULL;
	list->tail = NULL;
}

void PushBack(LinkedList* list, int val)
{
	Node* added_node = calloc(1, sizeof(*added_node));
	added_node->val = val;
	if (IsEmpty(list))
	{
		list->head = list->tail = added_node;
		added_node->next = added_node;
		added_node->prev = added_node;

		return;
	}

	list->tail->next = added_node;
	list->head->prev = added_node;
	added_node->prev = list->tail;
	added_node->next = list->head;
	list->tail = added_node;
}

bool IsEmpty(const LinkedList* list)
{
	return list->tail == NULL && list->head == NULL;
}

void DeleteNode(Node* node)
{
	node->next = node->prev = NULL;
	node->val = 0;
	free(node);
}

void InitialLoop(LinkedList* list, int size)
{
	Init(list);

	for (int i = 1; i <= size; i++)
	{
		PushBack(list, i);
	}
}

void PrintLoop(const Node* cur_node)
{
	if (!cur_node)
	{
		printf("Print Null Node\n");
		exit(-1);
	}

	printf("%d\n", cur_node->val);
}

void Move(const LinkedList* list, int len, Node** cur_node, Node* (* OneMove)(const Node*))
{
	if (len > list->size / 2)
	{
		OneMove = (OneMove == &PrevMove) ? &NextMove : &PrevMove;
		len = list->size - len;
	}
	for (int i = 0; i < len; i++)
	{
		*cur_node = OneMove(*cur_node);
	}
}

Node* PrevMove(const Node* cur_node)
{
	if (!cur_node)
	{
		printf("Prev Move Null Node\n");
		exit(-1);
	}

	return cur_node->prev;
}

Node* NextMove(const Node* cur_node)
{
	if (!cur_node)
	{
		printf("Next Move Null Node\n");
		exit(-1);
	}

	return cur_node->next;
}

void InsertLoop(LinkedList* list, int num_insert, Node* input_node)
{
	list->size++;

	if (IsEmpty(list) || list->tail == input_node)
	{
		PushBack(list, num_insert);
		return;
	}

	if (!input_node)
	{
		printf("Insert (not pushback) from Null input Node\n");
		exit(-1);
	}

	Node* insert_node = calloc(1, sizeof(*insert_node));
	insert_node->val = num_insert;
	Node* next_node = input_node->next;

	input_node->next = insert_node;
	next_node->prev = insert_node;
	insert_node->next = next_node;
	insert_node->prev = input_node;
}

// * notice that list input can't be empty and can't be single.
Node* RemoveLoop(LinkedList* list, Node* cur_node)
{
	if (!cur_node)
	{
		printf("Remove NULL list\n");
		exit(-1);
	}

	if (list->head == list->tail)
	{
		printf("Single list\n");
		exit(-2);
	}

	list->size--;

	Node* prev = cur_node->prev;
	Node* next = cur_node->next;

	if (cur_node == list->head)
		list->head = next;
	if (cur_node == list->tail)
		list->tail = prev;

	next->prev = prev;
	prev->next = next;

	DeleteNode(cur_node);

	return next;
}

// * list can't be NULL.
void FreeLoop(LinkedList* list)
{
	while (list->head != list->tail)
	{
		RemoveLoop(list, list->head);
	}
	DeleteNode(list->head);

	list->head = list->tail = NULL;
	list->size = 0;
}


/**

4 7
Forward 7
Backward 5
Print
Remove
Insert 114514
Forward 2
Print

 */


