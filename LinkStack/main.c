#include <stdio.h>
#include "linkstack.h"
int main(){
	LinkStack* stack = LinkStack_Create();

	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	int i4 = 4;
	int i5 = 5;
	int i6 = 6;

	LinkStack_Push(stack,&i1);
	LinkStack_Push(stack,&i2);
	LinkStack_Push(stack,&i3);
	LinkStack_Push(stack,&i4);
	LinkStack_Push(stack,&i5);
	LinkStack_Push(stack,&i6);
	
	printf("size - %d\n",LinkStack_Size(stack));
	int top = *(int*)LinkStack_Top(stack);
	printf("top - %d\n",top);
	printf("-------------------------------------\n");
	while(LinkStack_Size(stack)>0){
		int v = *(int*)LinkStack_Pop(stack);
		printf("-->%d\n",v);
	}
	LinkStack_Destroy(stack);
	return 0;
}
