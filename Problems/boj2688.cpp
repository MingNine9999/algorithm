//Problem Number : 2688
//Problem Title : 줄어들지 않아
//Problem Link : https://www.acmicpc.net/problem/2688

#include <iostream>

using namespace std;

long long dp[1001][10];

int main() {
	int t;
	cin >> t;
	
	int memo = 1;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < 10; i++) {
			dp[1][i] = 1;
		}

		for (int i = memo + 1; i <= n; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = j; k < 10; k++) {
					dp[i][k] += dp[i - 1][j];
				}
			}
			memo++;
		}

		long long ans = 0;
		for (int i = 0; i < 10; i++) {
			ans += dp[n][i];
		}

		cout << ans << "\n";
	}

	return 0;
}