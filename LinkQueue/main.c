#include <stdio.h>
#include "linkqueue.h"
int main() {
    LinkQueue* queue = LinkQueue_Create();
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (int i = 0;i < 10;i++) {
        LinkQueue_Append(queue, a + i);
    }
    printf("Length:%d\n", LinkQueue_Length(queue));
    printf("Header:%d\n", *(int*)LinkQueue_Header(queue));
    while (LinkQueue_Length(queue) > 0) {
        int* v = (int*)LinkQueue_Retrieve(queue);
        printf("-->%d\n", *v);
    }
    return 0;
}
