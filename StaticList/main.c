#include <stdio.h>
#include "staticlist.h"

int main() {
    StaticList* list = StaticList_Create(5);
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    StaticList_Insert(list, &a, 0);
    StaticList_Insert(list, &b, 1);
    StaticList_Insert(list, &c, 2);
    for (int i = 0 ; i < StaticList_Szie(list);i++) {
        int* ret = (int*)StaticList_Get(list, i);
        printf("%d\n", *ret);
    }
    
	printf("----------\n");

    StaticList_Insert(list, &c, 3);
    StaticList_Insert(list, &d, 2);
    StaticList_Insert(list, &e, 2);
    for (int i = 0 ; i < StaticList_Szie(list);i++) {
        int* ret = (int*)StaticList_Get(list, i);
        printf("%d\n", *ret);
    }

    return 0;
}
