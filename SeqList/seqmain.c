#include <stdio.h>
#include "seqlist.h"
int main(){
	SeqList* seqlist = SeqList_Create(5);

	int a = 11;
	int b = 22;
	int c = 33;

	SeqList_Insert(seqlist,&a,0);
	SeqList_Insert(seqlist,&b,1);
	SeqList_Insert(seqlist,&c,2);

	for(int i=0;i<SeqList_Length(seqlist);i++){
		int* node = (int*)SeqList_Get(seqlist,i);
		printf("node[%d]-->%d\n",i,*node);
	}
	printf("---------------DELETE 2-------------------------------\n");
	SeqList_Delete(seqlist,2);
	for(int i=0;i<SeqList_Length(seqlist);i++){
		int* node = (int*)SeqList_Get(seqlist,i);
		printf("node[%d]-->%d\n",i,*node);
	}
	int capacity = SeqList_Capacity(seqlist);
	printf("Capacity:%d\n",capacity);
	printf("Length  :%d\n",SeqList_Length(seqlist));
	SeqList_Destroy(seqlist);
	return 0;
}
