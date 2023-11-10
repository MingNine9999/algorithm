//Problem Number : 11057
//Problem Title : 오르막 수
//Problem Link : https://www.acmicpc.net/problem/11057

#include <iostream>

using namespace std;

int dp[1001][10];

int main() {
	int n;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	cin >> n;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][k] += dp[i - 1][j];
			}

			if (dp[i][j] > 10007) {
				dp[i][j] %= 10007;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
	}
	if (ans > 10007) {
		ans %= 10007;
	}

	cout << ans;

	return 0;
}