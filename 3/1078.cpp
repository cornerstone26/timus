#include <iostream>
#include <vector>
using namespace std;
#define MAXN 505

int l[MAXN], r[MAXN], id[MAXN], dp[MAXN];
int n;
vector <int> res[MAXN];
void printArr(int a[], int n) {
	for (int i = 0; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quickSort(int a[], int b[], int id[], int left, int right) {
	int i = left, j = right;
	int x = left + (right - left) / 2;
	int pivot = b[x] - a[x];

	while (i <= j) {

		while (b[i] - a[i] > pivot ) i++;
		while (b[j] - a[j] < pivot ) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			swap(b[i], b[j]);
			swap(id[i], id[j]);
			++i;
			--j;
		}
	}
	if (j > left) quickSort(a, b, id, left, j);
	if (i < right) quickSort(a, b, id, i, right);

}

int max(int a[], int n){
    
    int ret = 0;
    
    for (int i = 1; i <= n; i++){
        if (a[i] > a[ret]){
            ret = i;
        }
    }
    return ret;
}

int main() {
    
	cin >> n;

	for (int i = 1; i <= n; i++){
	    cin >> l[i] >> r[i];
	    dp[i] = 1;
	    id[i] = i;
	    res[i].push_back(i);
	}
    
	quickSort(l, r, id, 1, n);
	int save_k;

    for (int i = 1; i <= n; i++){
        for (int k = 1; k < i; k++){
            if (l[i] > l[k] && r[i] < r[k] && dp[id[i]] <= dp[id[k]]){
                dp[id[i]] = dp[id[k]] + 1;
                save_k = k;
            }
            
        }
        res[id[i]].push_back(id[save_k]);
    }
    
    int id = max(dp,n);

    cout << dp[id] << endl;
    cout << res[id][0] << " ";
    while (dp[id] != 1){
        for (int i = res[id].size() - 1; i > 0 ; i--){
            cout << res[id][i] << " ";
        }
        id = res[id].back();
    }
    
    return 0;
}