//Problem Number : 11726
//Problem Title : 2×n 타일링
//Problem Link : https://www.acmicpc.net/problem/11726

#include <iostream>

using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
		if (dp[i] > 10007) {
			dp[i] = dp[i] % 10007;
		}
	}

	cout << dp[n];

	return 0;
}