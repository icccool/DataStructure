#include <stdio.h>
#include <malloc.h>

#include "staticlist.h"

#define AVAILABLE -1

typedef struct _tag_StaticListNode {
    int data;
    int next;
} TStaticListNode;

typedef struct _tag_StaticList {
    int catacity;
    TStaticListNode header;
    TStaticListNode node[];
} TStaticList;

StaticList* StaticList_Create(int catacity) {
    TStaticList* list = NULL;
    if (catacity > 0 ) {
        list = (TStaticList*)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * (catacity + 1));
    }
    if (list != NULL) {
        list->catacity = catacity;
        list->header.data = 0;
        list->header.next = 0;
        for (int i = 1; i <= catacity; i++ ) {
            list->node[i].next = AVAILABLE;
        }
    }
    return list;
}

StaticListNode* StaticList_Get(StaticList* list, int pos) {
    TStaticList* sList = (TStaticList*)list;
    StaticListNode* ret = NULL;
    if (sList != NULL && pos >= 0 && pos < sList->header.data) {
        int current = 0;
        sList->node[0] = sList->header;
        for (int i = 0;i <= pos ; i++) {
            current = sList->node[current].next;
        }
        ret = (StaticListNode*)sList->node[current].data;
    }
    return ret;
}

int StaticList_Insert(StaticList* list, StaticListNode* node, int pos) {

    TStaticList* sList = (TStaticList*)list;
    int  ret = (sList->header.data + 1 <= sList->catacity);
    ret = ret && (sList != NULL) && (pos >= 0) && (node != NULL);
    if (ret) {
        //找到空闲位置
        int index = 0;
        sList->node[0] = sList->header;
        for (int i = 1;i <= sList->catacity; i++) {
            if (sList->node[i].next == AVAILABLE) {
                index = i;
                break;
            }
        }
        //赋值数据
        sList->node[index].data = (unsigned int)node;
        //加入链表,建立连接
        int current = 0;
        for (int i = 0; (i < pos) && (sList->node[current].next != 0);i++) {
            current = sList->node[current].next;
        }
        sList->node[index].next = sList->node[current].next;
        sList->node[current].next = index;
        sList->node[0].data++;
        sList->header = sList->node[0];
    }
    return ret;
}

StaticListNode* StaticList_Delete(StaticList* list, int pos) {
    TStaticList* sList = (TStaticList*)list;
    StaticListNode* del = NULL;
    if (sList != NULL && pos >= 0 && pos < sList->header.data) {
        int current = 0;
        sList->node[0] = sList->header;
        for (int i = 0;(i < pos) && (sList->node[current].next != 0) ; i++) {
            current = sList->node[current].next;
        }
        //要删除的节点
        int ret = sList->node[current].next;
        sList->node[current].next = sList->node[ret].next;
        sList->node[ret].next = AVAILABLE;
        sList->node[0].data --;
        sList->header = sList->node[0];
        del = (StaticListNode*)(sList->node[ret].data);
    }
    return del;
}

void disdroy(StaticList* list) {
    TStaticList* sList = (TStaticList*)list;
    if (sList != NULL) {
        free(list);
    }
}

void clear(StaticList* list) {
    TStaticList* sList = (TStaticList*)list;
    if (sList != NULL) {
        for (int i = 1; i <= sList->catacity; i++ ) {
            sList->node[i].next = AVAILABLE;
        }
        sList->header.next = 0;
        sList->header.data = 0;
    }
}


int StaticList_Szie(StaticList* list) {
    TStaticList* sList = (TStaticList*)list;
    int ret = 0;
    if (sList != NULL) {
        ret = sList->header.data;
    }
    return ret;
}

int StaticList_Catacity(StaticList* list) {
    TStaticList* sList = (TStaticList*)list;
    int ret = 0;
    if (sList != NULL) {
        return sList->catacity;
    }
    return ret;
}
