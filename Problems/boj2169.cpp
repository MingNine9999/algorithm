//Problem Number : 2169
//Problem Title : 로봇 조종하기
//Problem Link : https://www.acmicpc.net/problem/2169

#include <iostream>
#include <algorithm>

using namespace std;

const int goY[] = { 0,1,0,-1 };
const int goX[] = { 1,0,-1,0 };
int MAP[1111][1111];
int dp[1111][1111];
int dp2[1111][1111];

int n, m;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[0][i] = dp[n + 1][i] = dp[i][n + 1] = -1234567890;
		dp2[i][0] = dp2[0][i] = dp2[n + 1][i] = dp2[i][n + 1] = -1234567890;
		for (int j = 1; j <= m; j++) {
			cin >> MAP[i][j];
		}
	}
	dp[1][1] = dp2[1][1] = MAP[1][1];
	dp[2][1] = dp2[2][1] = dp[1][1] + MAP[2][1];
	for (int i = 2; i <= m; i++) {
		dp[1][i] = dp[1][i - 1] + MAP[1][i];
		dp2[1][i] = dp2[1][i - 1] + MAP[1][i];
		dp[2][i] = dp[1][i] + MAP[2][i];
		dp2[2][i] = dp2[1][i] + MAP[2][i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + MAP[i][j]);
		}
		for (int j = m; j >= 1; j--) {
			dp2[i][j] = max(dp2[i][j], dp2[i][j + 1] + MAP[i][j]);

			dp[i + 1][j] = dp2[i + 1][j] = max(dp[i][j], dp2[i][j]) + MAP[i + 1][j];
		}
	}

	cout << dp[n][m];

	return 0;
}