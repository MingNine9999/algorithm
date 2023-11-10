//Problem Number : 9095
//Problem Title : 1, 2, 3 더하기
//Problem Link : https://www.acmicpc.net/problem/9095

#include <iostream>

using namespace std;

int dp[11];

int main() {
	int t;
	cin >> t;

	int memo = 0;
	while (t--) {
		int n;
		cin >> n;

		for (int i = memo + 1; i <= n; i++) {
			for (int j = i - 1; j >= i - 3  && j > 0; j--) {
				dp[i] += dp[j];	
			}
			if (i <= 3) {
				dp[i]++;
			}
			memo++;
		}

		cout << dp[n] << "\n";
	}

	return 0;
}