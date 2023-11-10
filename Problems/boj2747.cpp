//Problem Number : 2747
//Problem Title : 피보나치 수
//Problem Link : https://www.acmicpc.net/problem/2747

#include <iostream>

using namespace std;

int dp[50];

int main() {
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

	return 0;
}