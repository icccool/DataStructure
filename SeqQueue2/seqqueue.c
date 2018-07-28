#include <stdio.h>
#include <malloc.h>
#include "seqqueue.h"

typedef int TSeqQueueNode;

typedef struct _tag_SeqQueue {
    int capacity;
    int front;
    int rear;
    TSeqQueueNode* node;
} TSeqQueue;

SeqQueue* SeqQueue_Create(int capacity) {
    TSeqQueue* queue = NULL;
    if (capacity > 0) {
        queue = (TSeqQueue*)malloc(sizeof(TSeqQueue) + sizeof(TSeqQueueNode) * capacity);
        if (queue != NULL) {
            queue->capacity = capacity;
            queue->front = 0;
            queue->rear = 0;
            queue->node = (TSeqQueueNode*)(queue + 1);
        }
    }
    return queue;
}

void SeqQueue_Destroy(SeqQueue* queue) {
    free(queue);
}

void SeqQueue_Clear(SeqQueue* queue) {

}

int SeqQueue_Append(SeqQueue* queue, void* item) {
    TSeqQueue* q = (TSeqQueue*)queue;
    // ( R + 1 ) % MAX == H
    int ret = (q != NULL) && (item != NULL) && ( SeqQueue_Length(queue) < q->capacity);
    if (ret) {
        q->node[q->rear] = (TSeqQueueNode)item;
        q->rear = (q->rear + 1) % q->capacity;
    }
    return ret;
}


void* SeqQueue_Retrieve(SeqQueue* queue) {
    TSeqQueue* q = (TSeqQueue*)queue;
    void* ret = NULL;
    if (q != NULL) {
        ret = (void*)q->node[q->front];
        q->front = (q->front + 1) % q->capacity;
    }
    return ret;
}

void* SeqQueue_Header(SeqQueue* queue) {
    TSeqQueue* q = (TSeqQueue*)queue;
    void* ret = NULL;
    if (q != NULL) {
        ret = (void*)q->node[q->front];
    }
    return ret;

}

int SeqQueue_Length(SeqQueue* queue) {
    TSeqQueue* q = (TSeqQueue*)queue;
    int ret = 0;
    if (q != NULL) {
        // (R - H + MAX ) % MAX;
        ret = (q->rear - q->front + q->capacity) % q->capacity;
    }
    return ret;
}

int SeqQueue_Capacity(SeqQueue* queue) {
    TSeqQueue* q = (TSeqQueue*)queue;
    int ret = 0;
    if (q != NULL) {
        ret = q->capacity;
    }
    return ret;
}
