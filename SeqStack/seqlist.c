#include <stdio.h>
#include <malloc.h>
#include "seqlist.h"
/*顺序存储列表*/
typedef unsigned int TSeqListNode;

typedef struct _SeqList {
    int catacity;
    int length;
    TSeqListNode* node;
} TSeqList;



SeqList* SeqList_Create(int catacity) {
    TSeqList* seqList = NULL;
    if (catacity >= 0 ) {
        seqList = (TSeqList*) malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * catacity);
    }
    if (seqList != NULL) {
        seqList-> catacity = catacity;
        seqList-> length = 0;
		//node指向数据区域
        seqList -> node = (TSeqListNode*)(seqList + 1);
    }
    return seqList;
}

void SeqList_Destory(SeqList* list) {
    free(list);
}

void SeqList_Clear(SeqList* list) {
    TSeqList* sList = (TSeqList*)list;
    if (sList != NULL) {
        sList->length = 0;
    }
}

int SeqList_Catacity(SeqList* list) {

    TSeqList* sList = (TSeqList*)list;
    int ret = -1;
    if (sList != NULL) {
        ret = sList->catacity;
    }
    return ret;
}

int SeqList_Length(SeqList* list) {
    TSeqList* sList = (TSeqList*)list;
    int ret = 0;
    if (sList != NULL) {
        ret = sList->length;
    }
    return ret;
}


int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) {

    TSeqList* sList = (TSeqList*)list;
    //列表是否为空
    int ret = (sList != NULL);
    //是否有足够的空间
    ret = ret && (sList->length + 1 <= sList->catacity);
    //插入位置是否有效
    ret = ret && 0 <= pos ;

    if (ret) {
        if (pos > sList->length) {
            pos = sList->length;
        }
        //移动数据
        for (int i = sList->length;i > pos;i--) {
            sList->node[i] =  sList->node[i-1];
        }
        sList->node[pos] = (TSeqListNode)node;
        sList->length++;
    }
    return ret;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) {
    SeqListNode* node = NULL;
    TSeqList* sList = (TSeqList*)list;
    if (sList != NULL && pos >= 0 && pos < sList->length) {
        node = (SeqListNode*)sList->node[pos];
    }
    return node;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos) {
    TSeqList* sList = (TSeqList*)list;
    SeqListNode* ret = SeqList_Get(list, pos);
    if (ret != NULL) {
        for (int i = pos+1; i < sList->length; i++) {
            sList->node[i-1]= sList->node[i];
        }
        sList->length -- ;
    }
    return ret;
}


