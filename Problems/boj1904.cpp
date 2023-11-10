//Problem Number : 1904
//Problem Title : 01타일
//Problem Link : https://www.acmicpc.net/problem/1904

#include <iostream>

using namespace std;

int dp[1000001];

int main() {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > 15746) {
			dp[i] %= 15746;
		}
	}

	cout << dp[n];

	return 0;
}