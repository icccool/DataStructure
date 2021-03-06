#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int catacity);

void SeqList_Destory(SeqList* list);

void SeqList_Clear(SeqList* list);

int SeqList_Catacity(SeqList* list);

int SeqList_Length(SeqList* list);

int SeqList_Insert(SeqList* list,SeqListNode* node,int pos);

SeqListNode* SeqList_Get(SeqList* list,int pos);

SeqListNode* SeqList_Delete(SeqList* list,int pos);

#endif
