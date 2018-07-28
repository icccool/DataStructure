#include <stdio.h>
int strlen(char* s) ;
int main() {
    int len = strlen("abc");
    printf("--> %d\n", len);
    return 0;
}

int strlen(char* s) {
    if (s != NULL) {
        if (*s != '\0') {
            return strlen(s + 1) + 1;
        } else {
            return 0;
        }
    } else {
        return -1;
    }
}
