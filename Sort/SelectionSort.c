#include <stdio.h>
#define ARRAYSIZE(A) (sizeof(A)/sizeof(*A))

void selectionSort(int arr[], int len) ;
void swap(int arr[], int i, int j) ;
void println(int arr[], int len) ;

int main() {
    int a[] = {21, 5, 31, 33, 28, 0, 9, 1};
    int len = sizeof(a) / sizeof(*a);
    println(a, len);
    selectionSort(a, len);
    println(a, len);
    return 0;
}

//从 n - i + 1 个记录中选取最小的记录和第i个记录交换
void selectionSort(int arr[], int len) {
    for (int i = 0;i < len;i++) {
        int k  = i;
        for (int j = i;j < len;j++) {
            if (arr[k] > arr[j]) {
                k = j;
            }
        }
        swap(arr, i, k);
    }
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void println(int arr[], int len) {
    for (int i = 0;i < len;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


