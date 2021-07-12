#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSort(int a[], int a_id[], int left, int right) {
	int i = left, j = right;
	int x = left + (right - left) / 2;
	int pivot = a[x];
	int pivot_id = a_id[x];

	while (i <= j) {

		while (a[i] < pivot || (a[i] == pivot && a_id[i] < pivot_id)) i++;
		while (a[j] > pivot || (a[j] == pivot && a_id[j] > pivot_id)) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			swap(a_id[i], a_id[j]);
			++i;
			--j;
		}
	}
	if (j > left) quickSort(a, a_id, left, j);
	if (i < right) quickSort(a, a_id, i, right);
}
int binarySearch(int a[], int a_id[], int key, int l, int r, int left, int right) {
	int index;
	while (left <= right) {
		index = left + (int)(right - left) / 2;
		int x = a[index];

		if (key == x && l <= a_id[index] && a_id[index] <= r) {
			return 1;
		}
		else if (key < x) {
			right = index - 1;
			binarySearch(a, a_id, key, l, r, left, right);
		}
		else if (key > x) {
			left = index + 1;
			binarySearch(a, a_id, key, l, r, left, right);
		}
		else if (l > a_id[index]) {
			left = index + 1;
			binarySearch(a, a_id, key, l, r, left, right);
		}
		else if (r < a_id[index]) {
			right = index - 1;
			binarySearch(a, a_id, key, l, r, left, right);
		}
	}
	return 0;
}
int main() {
	int n;
	cin >> n;
	int value[70000];
	int id[70000];
	for (int i = 0; i < n; i++) {
		cin >> value[i];
		id[i] = i;
	}
	quickSort(value, id, 0, n - 1);
	int q, l, r, x;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l >> r >> x;
		cout << binarySearch(value, id, x, l - 1, r - 1, 0, n - 1);
	}
	return 0;
}
