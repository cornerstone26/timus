#include <iostream>
using namespace std;
int number[20];
int res = 0;
int gnum(int i, int n, int k) {
	if (i > n) {
		res++;
		return 0;
	}
	else if (i == 1 || number[i - 1] == 0) {
		for (int j = 1; j < k; j++) {
			number[i] = j;
			gnum(++i, n, k);
			i--;
		}
	}
	else {
		for (int q = 0; q < k; q++) {
			number[i] = q;
			gnum(++i, n, k);
			i--;
		}
	}
	return res;
}

int main() {
	int N, K;
	cin >> N;
	cin >> K;
	gnum(1, N, K);
	cout << res;
}