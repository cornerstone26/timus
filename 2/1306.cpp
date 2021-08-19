#include <stdio.h>
#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int tmp;
    tmp = *a,
        * a = *b;
    *b = tmp;
}
void quickSort(int a[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = a[left + (int)(right - left) / 2];
    while (i <= j) {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;

        if (i <= j) {
            swap(&a[i], &a[j]);
            ++i;
            --j;
        }
    }
    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);

}


int main() {
    int N;
    scanf("%d", &N);
    int arr[125000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, N - 1);
    if (N % 2) {
        cout << arr[(N - 1) / 2];
    }
    else {
        //cout << "\n" << arr[N / 2 - 1] << " " << arr[N / 2];
        unsigned x = (arr[N / 2 - 1] + arr[N / 2]);
        printf("%.1f", x/2.0);
    }
    return 0;
}