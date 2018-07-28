#include <stdio.h>
#include <malloc.h>
#include "CircleList.h"

typedef struct _tag_CircleList {
    CircleListNode header;
    CircleListNode* slider;
    int length;
}TCircleList;

CircleList* CircleList_Create() {
    TCircleList* ret = (TCircleList*)malloc(sizeof(TCircleList));
    if (ret != NULL) {
        ret->header.next = NULL;
        ret->slider = NULL;
        ret->length = 0;
    }
    return ret;
}

void CircleList_Destroy(CircleList* list) {
    free(list);
}

void CircleList_Clear(CircleList* list) {
    TCircleList* sList = (TCircleList*)list;
    if (sList != NULL) {
        sList->header.next = NULL;
        sList->slider = NULL;
        sList->length = 0;
    }
}

int CircleList_Length(CircleList* list) {
    TCircleList* sList = (TCircleList*)list;
    if (sList != NULL) {
        return sList->length;
    }
    return 0;
}


int CircleList_Insert(CircleList* list, CircleListNode* node, int pos) {
    TCircleList* sList = (TCircleList*)list;
    int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
    if (ret) {
        CircleListNode* current = (CircleListNode*)sList;
        for (int i = 0;(i < pos) && (current->next != NULL);i++) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        //循环链表
        if (sList->length == 0) {
            sList->slider = node;
        }
        sList->length++;
        if (current == (CircleListNode*)sList) {
            CircleListNode* last = CircleList_Get(list, CircleList_Length(list) - 1);
            last->next = current->next;
        }
    }
    return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos) {
    TCircleList* sList = (TCircleList*)list;
    if (sList != NULL && pos >= 0) {
        CircleListNode* current = (CircleListNode*)sList;
        for (int i = 0;i < pos ;i++) {
            current = current->next;
        }
        return current->next;
    }
    return NULL;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos) {
    TCircleList* sList = (TCircleList*)list;
    if (sList != NULL && pos >= 0 && sList->length > 0 && sList->length > pos) {
        CircleListNode* current = (CircleListNode*)sList;
        CircleListNode* first  = sList->header.next;
        for (int i = 0;i < pos;i++) {
            current = current->next;
        }
        CircleListNode* ret = current->next;
        current->next = ret->next;
        sList->length--;
        if (ret == first) {
			CircleListNode* last = (CircleListNode*)CircleList_Get(list, sList->length - 1);
            sList->header.next = ret->next;
            last->next = ret->next;
        }
        if (sList->slider == ret) {
            sList->slider = ret->next;
        }
        if (sList->length == 0) {
            sList->header.next = NULL;
            sList->slider = NULL;
        }
        return ret;
    }
    return NULL;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node) {
    TCircleList* sList = (TCircleList*)list;
    if (sList != NULL && node != NULL) {
        int i;
        CircleListNode* ret = NULL;
        CircleListNode* current  = (CircleListNode*)list;
        for (i = 0;i < sList->length;i++) {
            if (node == current->next) {
                ret = current->next;
                break;
            }
            current = current->next;
        }
        if (ret != NULL) {
            CircleList_Delete(list, i);
        }
        return ret;
    }
    return NULL;
}

CircleListNode* CircleList_Reset(CircleList* list) {
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;
    if (sList != NULL) {
        sList->slider = sList->header.next;
        ret = sList->slider;
    }
    return ret;
}

CircleListNode* CircleList_Current(CircleList* list) {
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;
    if (sList != NULL) {
        ret = sList->slider;
    }
    return ret;
}

CircleListNode* CircleList_Next(CircleList* list) {
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;
    if (sList != NULL) {
        ret = sList->slider;
        sList->slider = ret->next;
    }
    return ret;
}

