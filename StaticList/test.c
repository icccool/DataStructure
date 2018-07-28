#include <stdio.h>

typedef void ListNode;

void f(ListNode* node);

int main() {
    //int a[] = {1, 2, 3};
    //printf("-->%d\n", a[6]);
	int a = 2;
	f(&a);
    return 0;
}

void f(ListNode* node){
	unsigned int data = (unsigned int)node;
	printf("%d",data);
}
