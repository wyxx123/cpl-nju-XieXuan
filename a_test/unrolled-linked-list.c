//
// Created by xiexu on 2023/2/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B 2000

#define MAX_ARRAY_SIZE 100009
char tmp_input[MAX_ARRAY_SIZE] = { 0 };

typedef struct node
{
	struct node* next;
	char string[B];
	int size;
} Node;

typedef struct List
{
	Node* head;
} L;
L list = { 0 };

Node* AddNodes(Node* cur, char* input, int size);
Node* FindNode(int* index_address);
void SplitNode(Node* cur, int index);
void CombineNode(Node* cur);

int main(void)
{
	int n = 0;
	int q = 0;
	scanf("%d%d%s", &n, &q, tmp_input);

	list.head = malloc(sizeof(Node));
	list.head->next = NULL;
	list.head->size = -1;

	AddNodes(list.head, tmp_input, (int)strlen(tmp_input));

	for (int i = 0; i < q; i++)
	{
		char input_q = 0;
		int index = 0;
		scanf(" %c%d", &input_q, &index);
		Node* dest = FindNode(&index);
		if (input_q == 'I')
		{
			SplitNode(dest, index);
			scanf("%s", tmp_input);
			Node* last = AddNodes(dest, tmp_input, (int)strlen(tmp_input));
			CombineNode(last);
			CombineNode(dest);
		}
		else //Q
		{
			printf("%c\n", dest->string[index - 1]);
		}
	}

	return 0;
}

/**
 *
 * @param cur
 * @param input
 * @param size
 * @return last node
 */
Node* AddNodes(Node* cur, char* input, int size)
{
	int insert_size = (size > B) ? B : size;
	Node* insert = malloc(sizeof(Node));
	insert->size = insert_size;
	insert->next = cur->next;
	cur->next = insert;
	strncpy(insert->string, input, insert_size);

	if (size > insert_size)
		return AddNodes(insert, input + insert_size, size - insert_size);
	return insert;
}

Node* FindNode(int* index_address)
{
	Node* cur = list.head->next;
	while (cur->size < *index_address)
	{
		*index_address -= cur->size;
		cur = cur->next;
	}

	return cur;
}

void SplitNode(Node* cur, int index)
{
	Node* next = malloc(sizeof(Node));
	next->size = cur->size - index;
	strncpy(next->string, (cur->string) + index, next->size);
	memset((cur->string) + index, 0, next->size);
	cur->size -= next->size;
	next->next = cur->next;
	cur->next = next;
}

void CombineNode(Node* cur)
{
	if (cur->size + cur->next->size < B)
	{
		Node* next = cur->next;
		strncpy((cur->string) + cur->size, next->string, next->size);
		cur->size += next->size;
		cur->next = next->next;
		free(next);
	}
}


