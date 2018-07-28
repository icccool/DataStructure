#include <stdio.h>

int fibonacci(int n) ;

int main() {
    int f = fibonacci(5);
    printf("f = %d\n", f);
    return 0;
}

int fibonacci(int n) {
    if (n > 0) {
        if (n <= 2) {
            return 1;
        } else {
            return fibonacci(n -1) + fibonacci(n - 2);
        }
    } else {
        return 0;
    }
}
