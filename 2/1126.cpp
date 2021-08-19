#include <iostream>
using namespace std;

int main() {
	int M; 
	cin >> M;
	int a[25000];
	int N = 0;
	do {
		cin >> a[N];
	} while (a[N++] != -1);

	for (int i = 0; i < N - M; i++) {
		int max = a[i];
		for (int j = i; j < i + M; j++) {
			if (a[j] > max) {
				max = a[j];
			}
		}
		cout << max << endl;
	}

	return 0;
}