//Problem Number : 2193
//Problem Title : 이친수
//Problem Link : https://www.acmicpc.net/problem/2193

#include <iostream>

using namespace std;

long long dp[100];

int main() {
	int n;
	cin >> n;

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

	return 0;
}