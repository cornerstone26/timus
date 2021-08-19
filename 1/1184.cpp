#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int cable[10000];
	for (int i = 0; i < N; i++) {
		float tmp;
		cin >> tmp;
		cable[i] = (int) (tmp * 100);
	}
	
	int l = 0, r = 10000000, sum, q;
	while (l != r) {
		sum = 0;
		q = (l + r) / 2 + 1;
		for (int i = 0; i < N; i++) {
			sum += cable[i] / q;
		}
		//cout << l << " " << r << " " << q << " " << sum << endl;
		if (sum < K) {
			r = q - 1;
		}
		else {
			l = q;
		}
		
	}
	printf("%.2f", (float) l/100);
	return 0;
}

