#include <stdio.h>
#include <iostream>
using namespace std;
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void bubbleSort_op(int M[], int ID[], int N) {
	int lastswap = N - 1;
	for (int i = 1; i < N; i++) {		
		int swapped = 1;
		int curswap = -1;
		for (int j = 0; j < lastswap; j++) {
			if (M[j] > M[j + 1]) {
				swap(M[j], M[j+1]);
				swap(ID[j], ID[j+1]);
				swapped = 0;
				curswap = j + 1;
			}
		}
			
		if (swapped) return;
		lastswap = curswap;
	}
}

int main() {
	int N;
	cin >> N;
	int ID[150000], M[150000];
	for (int i = 0; i < N; i++) {
		cin >> ID[i] >> M[i];
	}

	bubbleSort_op(M, ID, N);

	for (int i = N - 1; i >= 0; i--) {
		cout << ID[i] << " " << M[i] << endl;
	}

	return 0;
}
