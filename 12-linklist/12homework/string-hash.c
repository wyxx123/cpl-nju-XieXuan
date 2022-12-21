//
// Created by xiexu on 2022/12/17.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define STRLEN 700 //why? -- use char* !!
#define HASH_N 600000

typedef struct node
{
	char str[STRLEN];
	struct node* next;
} Node;

Node* hash_array_pointer_first_node[HASH_N] = { 0 };

int Hash(const char* s);
void InputString(const char* input);
void LinkedListInput(int output_hash, const char* input);
bool JudgeInArray(const char* input);
bool JudgeInLinkedList(int output_hash, const char* input);
void FreeLinkListArray(void);
void FreeLinkList(Node* head);

int main(void)
{
	int m = 0;
	int q = 0;
	scanf("%d%d", &m, &q);

	for (int i = 0; i < m; i++)
	{
		char input[STRLEN] = { 0 };
		scanf("%s", input);
		InputString(input);
	}

	for (int i = 0; i < q; i++)
	{
		char input[STRLEN] = { 0 };
		scanf("%s", input);
		bool result = JudgeInArray(input);
		printf((result == true) ? "Yes\n" : "No\n");
	}

	FreeLinkListArray();

	return 0;
}

int Hash(const char* s)
{
	int len = (int)strlen(s);
	int ret = 0;
	for (int i = 0; i < len; i++)
		ret = (ret + s[i] * (i + 1)) % HASH_N;
	return ret;
}

void InputString(const char* input)
{
	int ret = Hash(input);
	LinkedListInput(ret, input);
}

void LinkedListInput(int output_hash, const char* input)
{
	Node* node = malloc(sizeof *node);
	strcpy(node->str, input);
	node->next = hash_array_pointer_first_node[output_hash];
	hash_array_pointer_first_node[output_hash] = node;
}

bool JudgeInArray(const char* input)
{
	int ret = Hash(input);
	return JudgeInLinkedList(ret, input);
}

bool JudgeInLinkedList(int output_hash, const char* input)
{
	Node* cur = hash_array_pointer_first_node[output_hash];
	while (cur != NULL && strcmp(cur->str, input) != 0)
		cur = cur->next;

	return (cur == NULL) ? false : true;
}

void FreeLinkListArray()
{
	for (int i = 0; i < HASH_N; i++)
	{
		if (hash_array_pointer_first_node[i] != NULL)
		{
			FreeLinkList(hash_array_pointer_first_node[i]);
			hash_array_pointer_first_node[i] = NULL;
		}
	}

}

void FreeLinkList(Node* head)
{
	if (head == NULL)
		return;

	Node* prev = head;
	Node* cur = prev->next;
	while (cur != NULL)
	{
		free(prev);
		prev = cur;
		cur = cur->next;
	}
	free(prev);
}


