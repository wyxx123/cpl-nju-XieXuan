//
// Created by xiexu on 2022/12/26.
//
#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

// 203
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// * combined version
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			struct ListNode* next = cur->next;
			free(cur);
			cur = head = next;
		}
		else
		{
			while (cur->next != NULL && cur->next->val != val)
				cur = cur->next;

			if (cur->next == NULL)
				break;

			struct ListNode* next = cur->next;
			struct ListNode* next_next = next->next;
			free(next);
			cur->next = next_next;
		}
	}

	return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// * 大佬version -- 递归
struct ListNode* DLRemoveElements(struct ListNode* head, int val)
{
	if (head == NULL)
		return NULL;
	struct ListNode* res = removeElements(head->next, val);
	if (head->val == val)
	{
		return res;
	}
	else
	{
		head->next = res;
		return head;
	}
}

// 旋转链表 206

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* reverseList(struct ListNode* head)
{

}

