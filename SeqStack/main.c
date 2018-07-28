#include <stdio.h>
#include "seqstack.h"
int main() {
    SeqStack* stack = SeqStack_Create(10);

    int i1  = 1;
    int i2  = 2;
    int i3  = 3;
    int i4  = 4;
    int i5  = 5;
    int i6  = 6;
    int i7  = 7;
    int i8  = 8;
    int i9  = 9;
    int i0  = 0;

    SeqStack_Push(stack, (void*)&i1);
    SeqStack_Push(stack, (void*)&i2);
    SeqStack_Push(stack, (void*)&i3);
    SeqStack_Push(stack, (void*)&i4);
    SeqStack_Push(stack, (void*)&i5);
    SeqStack_Push(stack, (void*)&i6);
    SeqStack_Push(stack, (void*)&i7);
    SeqStack_Push(stack, (void*)&i8);
    SeqStack_Push(stack, (void*)&i9);
    SeqStack_Push(stack, (void*)&i0);
    while (SeqStack_Size(stack) > 0) {
        int *p = (int*)SeqStack_Pop(stack);
        printf("--->%d\n", *p);
    }
    return 0;
}
