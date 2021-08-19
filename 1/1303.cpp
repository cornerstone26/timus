#include <iostream>
using namespace std;
void printArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
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

int main() {
	int m;
	cin >> m;

	int arr_l[99999];
	int arr_r[99999];

	int i = 0;
	while (1) {
		cin >> arr_l[i] >> arr_r[i];
		if (arr_l[i] == 0 && arr_r[i] == 0)
			break;
		i++;
	}

	quickSort(arr_l, arr_r, 0, i - 1);

	//printArr(arr_l, i);
	//printArr(arr_r, i);
	int n = i;
	//cout << "n = " << n << endl;
	i = 0;
	int res_l[99999];
	int res_r[99999];
	int ir = 0;
	//cout << "1. i = " << i << "   ir = " << ir << endl;
	while (arr_l[i] <= 0 && i < n) {
		//cout << i << endl;
		i++;
	}
	i = i - 1;

	//cout << "2. i = " << i << "   ir = " << ir << endl;
	while (i < n) {
		//cout << "2.1 i = " << i << "   ir = " << ir << endl;
		res_l[ir] = arr_l[i];
		res_r[ir] = arr_r[i];
		while (res_l[ir] == arr_l[i] && i < n) {
			i++;
		}
		res_r[ir] = arr_r[--i];
		//cout << "arr_r[i] = " << arr_r[ir] << endl;
		if (arr_r[i] >= m) {
			break;
		}
		else {
			if (arr_l[i + 1] <= arr_r[i] && i < (n - 1)) {
				i++;
				ir++;
			}
			else if (arr_l[i + 1] > arr_r[i] && i < (n - 1)) {
				cout << "No solution";
				return 0;
			}
			else {
				break;
			}
		}

		//printArr(res_l, ir);
		//printArr(res_r, ir);
	}
	//printArr(res_l, ir + 1);
	//printArr(res_r, ir + 1);
	//cout << "3. i = " << i << "   ir = " << ir << endl;
	ir++;
	if (res_r[ir - 1] < m) {
		cout << "No solution ";
		return 0;
	}
	else {
		cout << ir << endl;
		for (int k = 0; k < ir; k++) {
			cout << res_l[k] << " " << res_r[k] << endl;
		}
	}

	return 0;
}
