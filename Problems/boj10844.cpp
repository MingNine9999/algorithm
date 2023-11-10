//Problem Number : 10844
//Problem Title : 쉬운 계단 수
//Problem Link : https://www.acmicpc.net/problem/10844

#include <iostream>

using namespace std;

int dp[102][10];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			if (dp[i][j] > 1000000000) {
				dp[i][j] %= 1000000000;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
		if (ans > 1000000000) {
			ans %= 1000000000;
		}
	}


	cout << ans;
	return 0;
}