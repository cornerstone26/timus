#include <stdio.h>
void swap(int* a, int* b) {
    int tmp;
    tmp = *a,
        * a = *b;
    *b = tmp;
}
void quickSort(int a[], int a1[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = a[left + (int)(right - left) / 2];
    while (i <= j) {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;

        if (i <= j) {
            swap(&a[i], &a[j]);
            swap(&a1[i], &a1[j]);
            ++i;
            --j;
        }
    }
    if (left < j) quickSort(a, a1, left, j);
    if (i < right) quickSort(a, a1, i, right);

}

int main() {
    int p;
    scanf("%d", &p);
    int a[p], b[p];

    for (int i = 0; i < p; i++) {
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] > b[i]) {
            swap(&a[i], &b[i]);
        }
    }
    quickSort(b, a, 0, p - 1);
    int resa[p], resb[p];
    resa[0] = a[0]; resb[0] = b[0];
    int index = 1;
    int i = 0;
    for (int j = 1; j < p; j++) {
        if (a[j] >= b[i]) {
            resa[index] = a[j];
            resb[index++] = b[j];
            i = j;
        }
    }
    printf("%d", index);
    for (i = 0; i < index; i++) {
        printf("\n%d %d", resa[i], resb[i]);
    }
    return 0;
}