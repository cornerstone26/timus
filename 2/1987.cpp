#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
struct segment {
	int sp;
	int ep;
} typedef segment;

int main() {
	int n, m, c;
	cin >> n;
	segment sm[100005];
	for (int i = 1; i <= n; i++) {
		cin >> sm[i].sp >> sm[i].ep;
	}

	int size = 0, index = 1;
	cin >> m;
	int stack[100000];
	for (int i = 0; i < m; i++) {
		cin >> c;
		while (1) {
			while (size > 0 && sm[stack[size - 1]].ep < c) {
				//cout << "pop " << size << " " << index << endl;
				size--;
			}
			while (index <= n && sm[index].sp <= c) {
				//cout << "push " << size << " " << index<< endl;
				stack[size] = index;
				index++;
				size++;

			}
			//cout << size << " " << index << endl;
			if (size == 0) {
				cout << "-1" << endl;
				break;
			}
			else if (sm[stack[size - 1]].ep >= c) {
				cout << stack[size - 1] << endl;
				break;
			}
		}
	}

	return 0;
}