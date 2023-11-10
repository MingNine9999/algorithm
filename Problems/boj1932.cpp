//Problem Number : 1932
//Problem Title : 정수 삼각형
//Problem Link : https://www.acmicpc.net/problem/1932

#include <iostream>

using namespace std;

int tri[501][501];
int ans[501][501];

int main() {

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	ans[0][0] = tri[0][0];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ans[i][j] = max(ans[i - 1][j - 1], ans[i - 1][j]) + tri[i][j];
		}
	}

	int Max = -1;

	for (int i = 1; i <= n; i++) {
		Max = max(ans[n][i], Max);
	}

	cout << Max;

	return 0;
}