#include <stdio.h>
#include <malloc.h>
#include "linklist.h"


typedef struct _tag_LinkList {
    LinkListNode header;
    int length;
} TLinkList;


LinkList* LinkList_Create() {
    TLinkList* list = (TLinkList*)malloc(sizeof(TLinkList));
    if (list != NULL) {
        list->length = 0 ;
        list->header.next = NULL;
    }
    return list;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos) {
    TLinkList* tlist = (TLinkList*)list;
    int ret = (list != NULL) && (node != NULL) && (pos >= 0);
    if (ret) {
        LinkListNode* current = (LinkListNode*)tlist;
        for (int i = 0;(i < pos) && (current->next != NULL);i++) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        tlist->length++;
    }
    return ret;
}



LinkListNode* LinkList_Get(LinkList* list, int pos) {
    TLinkList* tlist = (TLinkList*)list;
    if (list != NULL && pos >= 0 && pos < tlist->length) {
        LinkListNode* current = (LinkListNode*)tlist;
        for (int i = 0;i <= pos;i++) {
            current = current->next;
        }
        return current;
    }
    return NULL;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos) {
    TLinkList* tlist = (TLinkList*)list;
    if (tlist != NULL && pos >= 0 && tlist->length > pos) {
        LinkListNode* current = (LinkListNode*)tlist;
        for (int i = 0;(i < pos) && (current->next != NULL);i++) {
            current = current->next;
        }
        LinkListNode* delNode = current->next;
        current->next = delNode->next;
        tlist->length--;
        return delNode;
    }
    return NULL;
}

void LinkList_Clear(LinkList* list) {
    TLinkList* tlist = (TLinkList*)list;
    if (tlist != NULL) {
        tlist->header.next = NULL;
        tlist->length = 0;
    }
}

void LinkList_Destroy(LinkList* list) {
    free(list);
}

int LinkList_Length(LinkList* list) {
    TLinkList* tlist = (TLinkList*)list;
    int len = 0;
    if (tlist != NULL) {
        len = tlist->length;
    }
    return len;
}
