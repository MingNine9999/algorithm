//Problem Number : 9465
//Problem Title : 스티커
//Problem Link : https://www.acmicpc.net/problem/9465

#include <iostream>
#include <cstring>

using namespace std;

int input[100001][2];
int dp[100001][3];

int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		memset(input, 0, sizeof(input));
		memset(dp, 0, sizeof(dp));

		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> input[i][0];
		}
		for (int i = 1; i <= n; i++) {
			cin >> input[i][1];
		}

		for (int i = 1; i <= n; i++) {
			dp[i][0] = MAX(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = MAX(dp[i - 1][0], dp[i - 1][2]) + input[i][0];
			dp[i][2] = MAX(dp[i - 1][0], dp[i - 1][1]) + input[i][1];
		}
		
		int ans = MAX(dp[n][1], dp[n][2]);

		if (dp[n][0] > ans) {
			cout << dp[n][0];
		}
		else {
			cout << ans;
		}
		cout << "\n";
	}

	return 0;
}