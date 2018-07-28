#include <stdio.h>
#include "DLinkList.h"
typedef struct _tag_Node {
    DLinkListNode node;
    int value;
}Node;

int main() {
    DLinkList* list = DLinkList_Create();
    Node node1;
    Node node2;
    Node node3;
    Node node4;
    Node node5;
    Node node6;

    node1.value = 1;
    node2.value = 2;
    node3.value = 3;
    node4.value = 4;
    node5.value = 5;
    node6.value = 6;

    DLinkList_Insert(list, (DLinkListNode*)&node1, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&node2, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&node3, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&node4, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&node5, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&node6, DLinkList_Length(list));

    Node* current = (Node*)DLinkList_Get(list, 0);
    for (int i = 0;i < DLinkList_Length(list);i++) {
        printf("--> %d\n", current->value);
        current = (Node*)current->node.next;
    }

    printf("-------------反序打印---------------------------\n");

    current = (Node*)DLinkList_Get(list, DLinkList_Length(list) - 1);
    for (int i = 0;i < DLinkList_Length(list);i++) {
        printf("--> %d\n", current->value);
        current = (Node*)current->node.pre;
    }

    printf("-------------删除操作---------------------------\n");

    DLinkList_Delete(list, 0);
    DLinkList_Delete(list, 0);
    DLinkList_Delete(list, DLinkList_Length(list) - 1);
    DLinkList_Insert(list, (DLinkListNode*)&node6, DLinkList_Length(list));
    current = (Node*)DLinkList_Get(list, 0);
    for (int i = 0;i < DLinkList_Length(list);i++) {
        printf("--> %d\n", current->value);
        current = (Node*)current->node.next;
    }
    return 0;
}
