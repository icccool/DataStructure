#include <stdio.h>

typedef struct _tag_list {
    int header;
    int len;
}TLis;

int main() {
    TList list = {4, 2};
    int* a = (int*)( & list);
	printf("--->%d \n",*a);
}

