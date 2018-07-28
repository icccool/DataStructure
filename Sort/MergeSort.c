#include <stdio.h>
#include <limits.h>

void mergeSort(int arr[], int s, int e) ;
void println(int arr[], int len);
void merge(int arr[], int s, int m, int e);

int main() {
    int a[] = {2, 2, 5, 9 , 0, 12, 34, 11, 11, 2, 5, 1};
    int len = sizeof(a) / sizeof(*a);
    println(a, len);
    mergeSort(a, 0, len - 1);
    println(a, len);
    return 0;
}

void mergeSort(int arr[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}

void merge(int arr[], int p, int r, int q) {
    int n1 = r - p + 1;
    int n2 = q - r ;
    int L[n1+1];
    int R[n2+1];
    for (int i = 0;i < n1;i++) {
        L[i] = arr[p+i];
    }
    for (int j = 0;j < n2;j++) {
        R[j] = arr[r+1+j];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int m = 0, n = 0;
    for (int i = p;i <= q;i++) {
        if (R[m] <= L[n]) {
            arr[i] = R[m++];
        } else {
            arr[i] = L[n++];
        }
    }
}

void println(int arr[], int len) {
    for (int i = 0;i < len;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


