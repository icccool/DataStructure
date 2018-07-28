#include <stdio.h>
#include <malloc.h>
#include "linklist.h"
#include "linkstack.h"

typedef struct _tag_LinkStackNode {
    LinkListNode header;
    void* item;
} TLinkStackNode;

LinkStack* LinkStack_Create() {
    LinkStack* stack = LinkList_Create();
    return stack;
}

void LinkStack_Destroy(LinkStack* stack) {
    LinkList_Clear(stack);
    LinkList_Destory(stack);
}

void LinkStack_Clear(LinkStack* stack) {
    LinkList_Clear(stack);
}

int LinkStack_Push(LinkStack* stack, void* item) {
    int ret = (stack != NULL) && (item != NULL);
    if (ret) {
        TLinkStackNode* node = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
        if (node != NULL) {
            node->item = item;
            ret = LinkList_Insert(stack, (LinkListNode*)node, 0);
        }
    }
    return ret;
}

void* LinkStack_Pop(LinkStack* stack) {
	void* ret = NULL;
    if (stack != NULL) {
        TLinkStackNode* node = (TLinkStackNode*)LinkList_Delete(stack, 0);
        if (node != NULL) {
            ret =  node->item;
            free(node);
        }
    }
    return ret;
}

void* LinkStack_Top(LinkStack* stack) {
	void* ret = NULL;
    if (stack != NULL) {
        TLinkStackNode* node = (TLinkStackNode*)LinkList_Get(stack, 0);
        if (node != NULL) {
			ret = node->item;
        }
    }
    return ret;
}

int LinkStack_Size(LinkStack* stack) {
    return LinkList_Length(stack);
}
