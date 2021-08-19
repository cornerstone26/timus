#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	float a[3010], c[3010];
	cin >> a[0];
	cin >> a[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
	}

	c[0] = 0;
	for (int i = 1; i <= N; i++) {
		c[i] = c[i - 1] + i * c[i];
	}
	
	for (int i = N; i > 0; i--) {
		a[i] = a[0] / (i + 1.000000000);
		a[i] += a[i + 1] * (i / (i + 1.000000000));
		a[i] -= c[i] * (2.000000000 / (i + 1));
	}

	printf("%.2f", a[1]);
	return 0;
}


