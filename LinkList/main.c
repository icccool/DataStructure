#include <stdio.h>
#include "linklist.h"

struct Value{
	LinkListNode header;
	int val;
};

int main(){
	LinkList* list = LinkList_Create();

	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	struct Value v5;
	
	v1.val = 0;
	v2.val = 1;
	v3.val = 2;
	v4.val = 3;
	v5.val = 4;
	//插入
	LinkList_Insert(list,(LinkListNode*)&v1,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode*)&v2,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode*)&v3,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode*)&v4,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode*)&v5,LinkList_Length(list));
	//输入列表
	for(int i = 0; i< LinkList_Length(list);i++){
		struct Value* pv = (struct Value*)LinkList_Get(list,i);
		printf("val[%d] --> %d\n",i,pv->val);
	}
	printf("len --> %d\n",LinkList_Length(list));
	printf("---------------------[DELETE 1 ]-----------------------------------\n");
	
	//删除
	LinkList_Delete(list,1);
	// H->5->3->2->1->NULL
	// 执行插入后会使值为5的节点指向最后 即: H->5->NULL
	//LinkList_Insert(list,(LinkListNode*)&v5,8);
	
	//这里必须建节点插入
	//struct Value v6;
	//v6.val = 6;
	//LinkList_Insert(list,(LinkListNode*)&v6,8);

	//输出列表
	for(int i = 0; i< LinkList_Length(list);i++){
		struct Value* pv = (struct Value*)LinkList_Get(list,i);
		printf("val[%d] --> %d\n",i,pv->val);
	}

	printf("len --> %d\n",LinkList_Length(list));
	LinkList_Destroy(list);
	return 0;
}
