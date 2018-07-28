#include <stdio.h>

void shellSort(int arr[], int len) ;
void println(int arr[], int len) ;

int main() {
    int a[] = {21, 25, 49, 25, 16, 8};
    int len = sizeof(a) / sizeof(*a);
    println(a, len);
    shellSort(a, len);
    println(a, len);
    return 0;
}

void shellSort(int arr[], int len) {
    int temp = 0;
    int gap = len;
    do {
        gap = gap / 3 + 1;
        for (int i = gap;i < len;i += gap) {
            temp = arr[i];
            int j = i;
            while ( j > 0 && arr[j-gap] > temp) {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    } while (gap > 1);
}

void println(int arr[], int len) {
    for (int i = 0;i < len;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


