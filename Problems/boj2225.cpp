//Problem Number : 2225
//Problem Title : 합분해
//Problem Link : https://www.acmicpc.net/problem/2225

#include <iostream>

#define MOD 1000000000

using ll = long long;
using namespace std;

ll dp[222];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;

	cin >> n >> k;

	dp[0] = 1;
	
	for (int i = 0; i < k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[j] += dp[j - 1];
			dp[j] %= MOD;
		}
	}

	cout << dp[n];

	return 0;
}