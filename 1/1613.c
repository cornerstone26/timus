#include <stdio.h>
int search(int key, int a[], int l, int r) {
    for (int i = l - 1; i < r; i++) {
        if (key == a[i]) {
            return 1;
        }
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr0[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr0[i]);
    }

    int q;
    scanf("%d", &q);

    int l, r, x;
    for (int i = 0; i < q; i++) {
        scanf("%d", &l);
        scanf("%d", &r);
        scanf("%d", &x);
        printf("%d", search(x, arr0, l, r));
    }
    return 0;
}