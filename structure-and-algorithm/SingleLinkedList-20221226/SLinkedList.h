//
// Created by xiexu on 2022/12/26.
//

#ifndef FOUR_ZI_COMPETITION_C_STRUCTURE_AND_ALGORITHM_SINGLELINKEDLIST_20221226_SLINKEDLIST_H
#define FOUR_ZI_COMPETITION_C_STRUCTURE_AND_ALGORITHM_SINGLELINKEDLIST_20221226_SLINKEDLIST_H

typedef int SLLType;

typedef struct single_linked_listed_node
{
	SLLType data;
	struct single_linked_listed_node* next;
} SLLNode;

typedef struct single_linked_listed
{
	SLLNode* head;
} SLL;

void SLLPrint(const SLL* list);
SLLNode* SLLFindTail(const SLL* list);
void SLLPushBack(SLL* list, SLLType val);
void SLLInit(SLL* list);
void SLLPopFront(SLL* list);

#endif //FOUR_ZI_COMPETITION_C_STRUCTURE_AND_ALGORITHM_SINGLELINKEDLIST_20221226_SLINKEDLIST_H
