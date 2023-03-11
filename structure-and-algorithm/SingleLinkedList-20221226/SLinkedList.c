//
// Created by xiexu on 2022/12/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SLinkedList.h"

void SLLInit(SLL* list)
{
	list->head = NULL;
}

void SLLPrint(const SLL* list)
{
	SLLNode* cur = list->head;
	while (cur)
	{
		if (cur != list->head)
			printf(" -> ");

		printf("%d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/**
 * return NULL if the linked list is empty.
 * @param list
 * @return
 */
SLLNode* SLLFindTail(const SLL* list)
{
	SLLNode* cur = list->head;

	if (cur == NULL)
		return NULL;

	while (cur->next != NULL)
		cur = cur->next;
	return cur;
}

void SLLPushBack(SLL* list, SLLType val)
{
	SLLNode* add_node = malloc(1 * sizeof(*add_node));
	add_node->next = NULL;
	add_node->data = val;

	SLLNode* tail = SLLFindTail(list);

	if (tail == NULL)
		list->head = add_node;
	else
		tail->next = add_node;
}

void SLLPopFront(SLL* list)
{
	SLLNode* head = list->head;
	assert(head != NULL);

	list->head = head->next;
	free(head);
}

