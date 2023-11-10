//Problem Number : 9461
//Problem Title : 파도반 수열
//Problem Link : https://www.acmicpc.net/problem/9461

#include <iostream>

using namespace std;

long long dp[120];

int main() {
	int t;
	cin >> t;

	int check = 5;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	while (t--) {
		int n;
		cin >> n;

		for (int i = check + 1; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
			check++;
		}

		cout << dp[n] << "\n";
	}

	return 0;
}