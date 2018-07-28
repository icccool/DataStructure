#include <stdio.h>
void swap(int arr[], int a, int b) ;
void quickSort(int arr[], int p , int q) ;
void println(int arr[], int len) ;

int main() {
    int arr[] = {1, 5, 3, 2, 1, 22, 2, 1, 2, 42, 0};
    int len = sizeof(arr) / sizeof(*arr);
    println(arr, len);
    quickSort(arr, 0, len - 1);
    println(arr, len);
    return 0;
}

void quickSort(int arr[], int p , int q) {
    if (p >= q) {
        return;
    }
    int r = p;
    for (int i = p; i <= q;i++ ) {
        if (arr[i] > arr[q]) {
            swap(arr, r, i);
            r++;
        }
    }
    swap(arr, r, q);
    quickSort(arr, p, r - 1);
    quickSort(arr, r + 1, q);
}

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void println(int arr[], int len) {
    for (int i = 0;i < len;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
