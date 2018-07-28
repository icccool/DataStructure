#include <stdio.h>

void swap(int arr[], int a, int b) ;
void bubbleSort(int arr[], int len) ;
void println(int arr[], int len) ;

int main() {
    int a[] = {21, 5, 31, 33, 28, 0, 9, 1};
    int len = sizeof(a) / sizeof(*a);
    println(a, len);
    bubbleSort(a, len);
    println(a, len);
    return 0;
}

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void bubbleSort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0;j < len;j++) {
            if (arr[i] < arr[j]) {
                swap(arr, i, j);
            }
        }
    }
}

void println(int arr[], int len) {
    for (int i = 0;i < len;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
