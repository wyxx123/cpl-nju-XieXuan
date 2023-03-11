//
// Created by xiexu on 2022/12/26.
//
#include "SLinkedList.h"

void SLLTest1(void)
{
	SLL list;
	SLLInit(&list);


	SLLPushBack(&list, 1);
	SLLPushBack(&list, 2);

	SLLPrint(&list);

	SLLPushBack(&list, 3);
	SLLPushBack(&list, 4);

	SLLPrint(&list);

}

int main(void)
{
	SLLTest1();

	return 0;
}