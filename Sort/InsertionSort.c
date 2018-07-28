#include <stdio.h>
#define ARRAYSIZE(A) (sizeof(A)/sizeof(*A))

void insertionSort(int arr[], int len) ;
void println(int arr[], int len) ;

int main() {
    int a[] = {21, 5, 31, 33, 28, 0, 9, 1};
    println(a, ARRAYSIZE(a));
    insertionSort(a, ARRAYSIZE(a));
    println(a, ARRAYSIZE(a));
    return 0;
}

void insertionSort(int arr[], int len) {
    int temp = 0;
    for (int i = 1;i < len;i++) {
        temp = arr[i];
        int j = i;
        while ( j > 0 && arr[j-1] > temp) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}

void println(int arr[], int len) {
    for (int i = 0;i < len;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


