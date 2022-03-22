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

		while (a[i] > pivot ) i++;
		while (a[j] < pivot ) j--;
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
    
	quickSort(arr_r, arr_l, 0, i - 1);
	int n = i;
	i = 0;
	int res_l[99999];
	int res_r[99999];
	int ir = 0; 
	int key = 0;

    while (i < n){
        if (arr_l[i] <= key && arr_r[i] >= key){
            res_l[ir] = arr_l[i];
            res_r[ir] = arr_r[i];
            key = arr_r[i];
            i = 0;
            ir++;
        } else {
            i++;
        }
        
        if (res_r[ir - 1] >= m){
            goto END;
        }
        if (ir == n){
            goto END;
        }
    }

END:

	if (res_r[ir - 1] < m){
	    cout << "No solution";
	    return 0;
	} else {
	    cout << ir << endl;
	    for (int k = 0; k < ir; k++){
	        cout << res_l[k] << " " << res_r[k] << endl;
	    }
	}
	return 0;

}