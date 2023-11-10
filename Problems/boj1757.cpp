//Problem Number : 1757
//Problem Title : 달려달려
//Problem Link : https://www.acmicpc.net/problem/1757

#include <iostream>
#include <algorithm>

using namespace std;

int run[10001];
int dp[10001][501];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> run[i];
	}


	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

		for (int j = 1; j <= i && j <= m; j++) {
			dp[i][j] = dp[i - 1][j - 1] + run[i];
			dp[i][0] = max(dp[i][0], dp[i - j][j]);
		}
	}

	cout << dp[n][0];

	return 0;
}
