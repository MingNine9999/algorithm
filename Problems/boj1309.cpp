//Problem Number : 1309
//Problem Title : 동물원
//Problem Link : https://www.acmicpc.net/problem/1309

#include <iostream>

using namespace std;

int dp[100001];

int main() {
	int n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] * 2 + dp[i - 2];
		if (dp[i] > 9901) {
			dp[i] %= 9901;
		}
	}

	cout << dp[n];

	return 0;
}