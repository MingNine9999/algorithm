//Problem Number : 2804
//Problem Title : 크로스워드 만들기
//Problem Link : https://www.acmicpc.net/problem/2804

#include <iostream>

using namespace std;

char a[35];
char b[35];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b;

	int aSel = -1;
	int bSel = -1;
	for (int i = 0; a[i] != 0; i++) {
		for (int j = 0; b[j] != 0; j++) {
			if (a[i] == b[j]) {
				aSel = i;
				bSel = j;
				break;
			}
		}
		if (aSel != -1) {
			break;
		}
	}

	for (int j = 0; b[j] != 0; j++) {
		for (int i = 0; a[i] != 0; i++) {
			if (j == bSel) {
				cout << a[i];
			}
			else if (i == aSel) {
				cout << b[j];
			}
			else {
				cout << '.';
			}
		}
		cout << "\n";
	}
	return 0;
}