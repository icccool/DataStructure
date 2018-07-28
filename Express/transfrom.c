#include <stdio.h>
#include "linkstack.h"
#include "linklist.h"
#define MAXLEN 50
/*
* ./transfrom 9+\(3-1\)*5+8/2
*  931-5*+82/+
*  程序传递'('参数要加'\'转义
*/
int priority(char c) ;
int isOpertor(char c) ;
int isDigit(char c) ;
void transfrom(char* s, char a[]) ;

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char a[MAXLEN];
        transfrom(argv[1], a);
        printf("%s\n", a);
    }
    return 0;
}

void transfrom(char* s, char a[]) {
    LinkStack* stack = LinkStack_Create();
    int i = 0, n = 0;
    while (s[i] != '\0') {
        if (isDigit(s[i])) {
            a[n++] = s[i];
        } else if (s[i] == '(') {
            LinkStack_Push(stack, (void*)(int)s[i]);
        } else if (s[i] == ')') {
            char c;
            while ((c = (char)(int)LinkStack_Pop(stack)) != '(') {
                a[n++] = c;
            }
        } else if (isOpertor(s[i])) {
            while (priority(s[i]) <= priority((char)(int)LinkStack_Top(stack))) {
                a[n++] = (char)(int)LinkStack_Pop(stack);
            }
            LinkStack_Push(stack, (void*)(int)s[i]);
        }
        i++;
    }
    while (LinkStack_Size(stack) > 0  && s[i] == '\0') {
        a[n++] = (char)(int)LinkStack_Pop(stack);
    }
    a[n] = '\0';
    LinkStack_Destroy(stack);
}

int priority(char c) {
    int p = 0;
    switch (c) {
    case '*':
    case '/':
        p = 3;
        break;
    case '+':
    case '-':
        p = 2;
        break;
    case '(':
        p = 1;
        break;
    default:
        p = 0;
        break;
    }
    return p;
}

int isOpertor(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}
