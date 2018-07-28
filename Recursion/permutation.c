#include <stdio.h>
#include <string.h>
void swap(char *s, int i, int j) ;
void permutation(char* s, int b, int e) ;
int main() {
    char s[]  = "ab";
    permutation(s, 0, 1);
    return 0;
}

void permutation(char* s, int b, int e) {
    if ( 0 <= b && b <= e ) {
        if (b == e) {
            printf("%s\n", s);
        } else {
            for (int i = b;i <= e;i++) {
                swap(s, b, i);
                permutation(s, b + 1, e);
                swap(s, b, i);
            }
        }
    }
}

void swap(char *s, int i, int j) {
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
}
