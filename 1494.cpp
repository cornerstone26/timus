#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int arr[100001];
	int top = 0, i = 0, cur_ball, ball = 1;
	arr[0] = 0;
	while (i != N) {
		cin >> cur_ball;
		while (arr[top] != cur_ball && ball <= N) {
			arr[++top] = ball++;
		}		
		if (arr[top] == cur_ball) {
			top--;
		}
		else {
			cout << "Cheater";
			return 0;
		}
		i++;
	}

	if (top == 0) {
		cout << "Not a proof";
	}
	return 0;
}