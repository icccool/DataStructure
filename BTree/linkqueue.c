#include <stdio.h>
#include <malloc.h>
#include "linklist.h"
#include "linkqueue.h"

typedef struct _tag_QueueNode {
    LinkListNode node;
    void* item;
} TQueueNode;

LinkQueue* LinkQueue_Create() {
    return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue* queue) {
    LinkList_Destroy(queue);
}

void LinkQueue_Clear(LinkQueue* queue) {
	while(LinkList_Length(queue) > 0){
		LinkQueue_Retrieve(queue);
	}
}

int LinkQueue_Append(LinkQueue* queue, void* item) {
    TQueueNode* node = (TQueueNode*)malloc(sizeof(TQueueNode));
    int ret = (queue != NULL) && (node != NULL) && (item != NULL);
    if (ret) {
        node->item = item;
        ret = LinkList_Insert(queue, (LinkListNode*)node, LinkList_Length(queue));
    }
	return ret;
}

void* LinkQueue_Retrieve(LinkQueue* queue) {
	void* ret = NULL;
	if(queue != NULL){
		TQueueNode* node = (TQueueNode*)LinkList_Delete(queue,0);
		if(node != NULL){
			ret = node->item;
			free(node);
		}
	}
	return ret;
}

void* LinkQueue_Header(LinkQueue* queue) {
	void* ret = NULL;
	if(queue != NULL){
		TQueueNode* node = (TQueueNode*)LinkList_Get(queue,0);
		if(node != NULL){
			ret = node->item;
		}
	}
	return ret;
}

int LinkQueue_Length(LinkQueue* queue) {
	return LinkList_Length(queue);
}

