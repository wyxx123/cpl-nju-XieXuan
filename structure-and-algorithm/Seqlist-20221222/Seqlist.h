//
// Created by xiexu on 2022/12/22.
//

#ifndef FOUR_ZI_COMPETITION_C_STRUCTURE_AND_ALGORITHM_SEQLIST_20221222_SEQLIST_H
#define FOUR_ZI_COMPETITION_C_STRUCTURE_AND_ALGORITHM_SEQLIST_20221222_SEQLIST_H

typedef int SLDataType;

typedef struct seqlist
{
	SLDataType* base;
	int size;
	int capacity;
} SL;

void InitSeqList(SL* seq_list);
void PushSeqListBack(SL* seq_list, SLDataType insert);

#endif //FOUR_ZI_COMPETITION_C_STRUCTURE_AND_ALGORITHM_SEQLIST_20221222_SEQLIST_H
