#include <stdio.h>
#include "linkstack.h"

int isRight(char c);
int isLeft(char c);
int scanner(const char* code);
int match(char left, char right);

int main() {
    const char* code = "#include <stdio.h int main() { int a[5][5]; int (*p)[4]; p = a[0]; printf(\"%d\\n\", &p[3][3] - &a[3][3]); return 0; }";
    scanner(code);
    return 0;
}

int scanner(const char* code) {
    LinkStack* stack = LinkStack_Create();
    int ret = 0;
    int i = 0;
    while (code[i] != '\0') {
        if (isLeft(code[i])) {
            LinkStack_Push(stack, (void*)code + i);
        }
        if (isRight(code[i])) {
            char* left = (char*)LinkStack_Pop(stack);
            if (left == NULL || !match(*left, code[i])) {
                printf("%c does not match!\n", code[i]);
                break;
            }
        }
        i++;
    }
    if (LinkStack_Size(stack) == 0 && code[i] == '\0') {
        printf("Succeed!\n");
        ret = 1;
    } else {
        printf("Invalid code!\n");
		if(LinkStack_Size(stack) > 0){
			while(LinkStack_Size(stack) > 0){
				char* left = (char*)LinkStack_Pop(stack);
                printf("%c does not match!\n", *left);
			}
		}
        ret = 0;
    }
    LinkStack_Destroy(stack);
    return ret;
}

int match(char left, char right) {
    int ret = 0;
    switch (left) {
    case '<':
        ret = (right == '>');
        break;
    case '(':
        ret = (right == ')');
        break;
    case '{':
        ret = (right == '}');
        break;
    case '[':
        ret = (right == ']');
        break;
    case '\'':
        ret = (right == '\'');
        break;
    case '\"':
        ret = (right == '\"');
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int isLeft(char c) {
    int ret = 0;
    switch (c) {
    case '<':
    case '(':
    case '{':
    case '[':
    case '\'':
    case '\"':
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int isRight(char c) {
    int ret = 0;
    switch (c) {
    case '>':
    case ')':
    case '}':
    case ']':
    case '\'':
    case '\"':
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
