#include <iostream>
using namespace std;

int main() {
	int N, K, res = 1;
	cin >> N;
	cin >> K;
	int number[20];
	number[1] = K - 1;
	number[2] = number[1]*K;
	for (int i = 3; i <= N; i++) {
		number[i] = (number[i - 1] + number[i - 2]) * (K - 1);
	}
	cout << number[N];
}