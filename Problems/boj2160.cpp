//Problem Number : 2160
//Problem Title : 그림 비교
//Problem Link : https://www.acmicpc.net/problem/2160

#include <iostream>

using namespace std;

char picture[51][5][7];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> picture[i][j];
		}
	}
	int min = 1234567890;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int check = 0;
			for (int k = 0; k < 5; k++) {
				for (int l = 0; l < 7; l++) {
					if (picture[i][k][l] != picture[j][k][l]) {
						check++;
					}
				}
			}
			if (check < min) {
				min = check;
				a = i;
				b = j;
			}
		}
	}
	cout << a + 1 << " " << b + 1;

	return 0;
}