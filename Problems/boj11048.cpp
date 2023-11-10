//Problem Number : 11048
//Problem Title : 이동하기
//Problem Link : https://www.acmicpc.net/problem/11048

#include <iostream>
#include <algorithm>

using namespace std;

const int goY[] = { 0,1,1 };
const int goX[] = { 1,0,1 };

int MAP[1111][1111];
int dp[1111][1111];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int go = 0; go < 3; go++) {
				dp[i][j] = max(dp[i][j], dp[i - goY[go]][j - goX[go]]);
			}
			dp[i][j] += MAP[i][j];
		}
	}

	cout << dp[n][m];

	return 0;
}