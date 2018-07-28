#include <stdio.h>
#include <malloc.h>
#include "DLinkList.h"

typedef struct _tag_DLinkList {
    DLinkListNode header;
    DLinkListNode* slider;
    int length;
}TDLinkList;

DLinkList* DLinkList_Create() {
    TDLinkList* ret = (TDLinkList*)malloc(sizeof(TDLinkList));
    if (ret != NULL) {
        ret->header.next = NULL;
        ret->header.pre = NULL;
        ret->slider = NULL;
        ret->length = 0;
    }
    return ret;
}

void DLinkList_Destroy(DLinkList* list) {
    free(list);
}

void DLinkList_Clear(DLinkList* list) {
    TDLinkList* sList = (TDLinkList*)list;
    if (sList != NULL) {
        sList->header.pre = NULL;
        sList->header.next = NULL;
        sList->length = 0;
        sList->slider = NULL;
    }
}


int DLinkList_Length(DLinkList* list) {
    TDLinkList* sList = (TDLinkList*)list;
    int ret = 0;
    if (sList != NULL) {
        ret = sList->length;
    }
    return ret;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos) {
    TDLinkList* sList = (TDLinkList*)list;
    int ret = (sList != NULL) && (node != NULL) && (pos >= 0);
    if (ret) {
        DLinkListNode* current = (DLinkListNode*)sList;
        for (int i = 0;i < pos && i < sList->length;i++) {
            current = current->next;
        }
        DLinkListNode* nextNode = current->next;
        current->next = node;
        node->next = nextNode;
        if (nextNode != NULL) {
            nextNode->pre = current;
        }
        if (sList->length > 0) {
            node->pre = current;
        } else {
            node->pre = NULL;
        }
        sList->length++;
    }
    return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos) {
    TDLinkList* sList = (TDLinkList*)list;
    if (sList != NULL && pos >= 0 && pos < sList->length) {
        DLinkListNode* current = (DLinkListNode*)sList;
        for (int i = 0;i < pos ;i++) {
            current = current->next;
        }
        return current->next;
    }
    return NULL;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos) {
    TDLinkList* sList = (TDLinkList*)list;
    if (sList != NULL && pos >= 0 && 0 < sList->length && pos < sList->length) {
        DLinkListNode* current = (DLinkListNode*)sList;
        for (int i = 0;i < pos;i++) {
            current = current->next;
        }
        DLinkListNode* ret = current->next;
        current->next = ret->next;
        if (ret->next != NULL) {
            if (current == (DLinkListNode*)sList) {
                ret->next->pre = NULL;
            } else {
                ret->next->pre = current;
            }
        }
        sList->length--;
        return ret;
    }
    return NULL;
}

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node) {
    return NULL;
}

DLinkListNode* DLinkList_Reset(DLinkList* list) {
    return NULL;
}

DLinkListNode* DLinkList_Current(DLinkList* list) {
    return NULL;
}

DLinkListNode* DLinkList_Next(DLinkList* list) {
    return NULL;
}

DLinkListNode* DLinkList_Pre(DLinkList* list) {
    return NULL;
}
