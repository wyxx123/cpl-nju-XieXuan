//
// Created by xiexu on 2022/12/22.
//
#include <stdlib.h>
#include <stdio.h>
#include "Seqlist.h"

void InitSeqList(SL* seq_list)
{
	seq_list->base = NULL;
	seq_list->size = 0;
	seq_list->capacity = 0;
}

void PushSeqListBack(SL* seq_list, SLDataType insert)
{
	if (seq_list->capacity == seq_list->size)
	{
		int changed_capacity = seq_list->size ? seq_list->size * 2 : 4;
		SLDataType* new_base = realloc(seq_list->base, changed_capacity * sizeof(*new_base));

		if (new_base == NULL)
		{
			printf("wy_xx123: err in realloc in fuction PushSeqListBack.\n");
			exit(-1);
		}

		seq_list->base = new_base;
		seq_list->capacity = changed_capacity;
	}

	(seq_list->base)[(seq_list->size)++] = insert;
}
