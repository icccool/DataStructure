#include <stdio.h>
#include "linkstack.h"

int value(char c) ;
int isNumber(char c);
int isOpertor(char c);
int cal(int left, int right, char op) ;
int compute(char* s) ;

int main(int argc, char *argv[]) {
	int res = compute(argv[1]);
	printf("%d\n",res);
    return 0;
}

int compute(char* s) {
    LinkStack* stack = LinkStack_Create();
    int i = 0, res = 0;
    while (s[i] != '\0') {
        if (isNumber(s[i])) {
            LinkStack_Push(stack, (void*)value(s[i]));
        } else if (isOpertor(s[i])) {
            int right = (int)LinkStack_Pop(stack);
            int left = (int)LinkStack_Pop(stack);
            int ret = cal(left, right, s[i]);
            LinkStack_Push(stack, (void*)ret);
        }
        i++;
    }
    if (LinkStack_Size(stack) == 1 && s[i] == '\0') {
        res = (int)LinkStack_Pop(stack);
    }
    LinkStack_Destroy(stack);
    return res;
}

int cal(int left, int right, char op) {
    int ret = 0;
    switch (op) {
    case '+':
        ret = left + right;
        break;
    case '-':
        ret = left - right;
        break;
    case '*':
        ret = left * right;
        break;
    case '/':
        if (right > 0) {
            ret = left / right;
        }
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int value(char c) {
    return c -'0';
}

int isOpertor(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isNumber(char c) {
    return (c >= '0' && c <= '9');
}
