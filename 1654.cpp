#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	char res[200000];
	int icur = 0;
	res[0] = ' ';
	for (int i = 0; i < str.length(); i++) {
		if (res[icur] != str[i]) {
			res[++icur] = str[i];
		}
		else {
			icur--;
		}
	}
	for (int i = 1; i <= icur; i++) {
		cout << res[i];
	}

	return 0;
}