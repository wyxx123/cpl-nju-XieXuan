//
// Created by xiexu on 2023/2/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 12

typedef struct node
{
	char name[NAME_LEN];
	struct node* file1;
	struct node* file2;
} Node;

typedef struct system
{
	Node* root;
} System;
System sys = { 0 };

Node* FindNode(char* target, Node* base);
int CountFile(Node* base);
void RemoveFile(Node* base, char* target);

int main(void)
{
	sys.root = malloc(sizeof(Node));
	sys.root->file1 = NULL;
	sys.root->file2 = NULL;

	int n = 0;
	int q = 0;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		char cur[NAME_LEN] = { 0 };
		char prev[NAME_LEN] = { 0 };

		scanf("%12s%12s", cur, prev);
		if (*prev == '~')
			strncpy(sys.root->name, cur, NAME_LEN);
		else
		{
			Node* target = FindNode(prev, sys.root);
			if (target->file1 == NULL)
			{
				target->file1 = malloc(sizeof(Node));
				target->file1->file1 = NULL;
				target->file1->file2 = NULL;
				strncpy(target->file1->name, cur, NAME_LEN);
			}
			else
			{
				target->file2 = malloc(sizeof(Node));
				target->file2->file1 = NULL;
				target->file2->file2 = NULL;
				strncpy(target->file2->name, cur, NAME_LEN);
			}
		}
	}

	for (int i = 0; i < q; i++)
	{
		char command[NAME_LEN] = { 0 };
		char input[NAME_LEN] = { 0 };

		scanf("%12s%12s", command, input);

		if (*command == 'q')
		{
			Node* target = FindNode(input, sys.root);
			int count = CountFile(target);
			printf("%d\n", count);
		}
		else
		{
			RemoveFile(sys.root, input);
		}

	}

	return 0;
}

Node* FindNode(char* target, Node* base)
{
	Node* cur = base;
	if (!strncmp(target, cur->name, NAME_LEN))
		return cur;

	if (cur->file1 != NULL)
	{
		Node* ret = FindNode(target, cur->file1);
		if (ret != NULL)
			return ret;
	}

	if (cur->file2 != NULL)
	{
		Node* ret = FindNode(target, cur->file2);
		if (ret != NULL)
			return ret;
	}

	return NULL;
}

int CountFile(Node* base)
{
	int file1_count = 0;
	int file2_count = 0;

	if (base->file1 != NULL)
		file1_count = CountFile(base->file1);
	if (base->file2 != NULL)
		file2_count = CountFile(base->file2);

	return 1 + file1_count + file2_count;

}

void RemoveFile(Node* base, char* target)
{
	if (base->file1 != NULL && !strncmp(target, base->file1->name, NAME_LEN))
	{
		free(base->file1);
		base->file1 = NULL;
		return;
	}
	if (base->file2 != NULL && !strncmp(target, base->file2->name, NAME_LEN))
	{
		free(base->file2);
		base->file2 = NULL;
		return;
	}
	if (base->file1 != NULL)
		RemoveFile(base->file1, target);
	if (base->file2 != NULL)
		RemoveFile(base->file2, target);

}

