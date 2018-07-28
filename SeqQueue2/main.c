#include <stdio.h>
#include "seqqueue.h"
int main() {
    SeqQueue* queue = SeqQueue_Create(10);
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (int i = 0;i < 10 ; i++) {
        SeqQueue_Append(queue, a + i);
    }
    printf("Capacity:%d\n", SeqQueue_Capacity(queue));
    printf("Length:%d\n", SeqQueue_Length(queue));
    printf("Header:%d\n", *(int*)SeqQueue_Header(queue));
    for (int i = 0;i < 10 ; i++) {
        int* v = (int*)SeqQueue_Retrieve(queue);
        printf("--> %d\n", *v);
    }
    return 0;
}
