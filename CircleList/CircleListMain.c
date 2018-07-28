#include <stdio.h>
#include "CircleList.h"

typedef struct _tag_Node {
    CircleListNode node;
    int data;
}Node;

void printList(CircleList* list) {
    for (int i = 0 ;i < CircleList_Length(list);i++) {
        Node* node = (Node*)CircleList_Get(list, i);
        int data = node->data;
        printf("%d\n", data);
    }
}

int main() {
    CircleList* list =  CircleList_Create();
    Node n1;
    Node n2;
    Node n3;
    Node n4;
    Node n5;
    Node n6;
    Node n7;
    Node n8;

    n1.data = 1;
    n2.data = 2;
    n3.data = 3;
    n4.data = 4;
    n5.data = 5;
    n6.data = 6;
    n7.data = 7;
    n8.data = 8;

    CircleList_Insert(list, (CircleListNode*)&n1, 0);
    CircleList_Insert(list, (CircleListNode*)&n2, 0);
    CircleList_Insert(list, (CircleListNode*)&n3, 0);
    CircleList_Insert(list, (CircleListNode*)&n4, 0);
    CircleList_Insert(list, (CircleListNode*)&n5, 0);
    CircleList_Insert(list, (CircleListNode*)&n6, 0);
    CircleList_Insert(list, (CircleListNode*)&n7, 0);
    CircleList_Insert(list, (CircleListNode*)&n8, 0);

    //CircleList_DeleteNode(list, (CircleListNode*)&n1);
    printf("------------打印列表 * 2--------------------------\n");
    for (int i = 0;i < CircleList_Length(list) * 2;i++) {
        //Node* node = (Node*)CircleList_Next(list);
        Node* node = (Node*)CircleList_Get(list, i);
        printf("%d\n", node->data);
    }
    //约瑟夫问题
    //CircleList_Reset(list);
    //while (CircleList_Length(list) > 0) {
    //    Node* val = NULL;
    //    for (int i = 1;i < 3;i++) {
    //        CircleList_Next(list);
    //    }
    //    val = (Node*)CircleList_Current(list);
    //    printf("--> %d\n", val->data);
    //    CircleList_DeleteNode(list, (CircleListNode*)val);
    //}
    //CircleList_Destroy(list);
    return 0;
}
