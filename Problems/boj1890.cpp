//Problem Number : 1890
//Problem Title : 점프
//Problem Link : https://www.acmicpc.net/problem/1890

#include <iostream>
#include <vector>
#include <queue>

using ll = long long;
using namespace std;

struct XY {
	int y;
	int x;

	bool operator <(XY a) const {
		return y + x > a.y + a.x;
	}
};

int MAP[111][111];
ll dp[111][111];
priority_queue<XY> pq;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> MAP[i][j];
		}
	}

	dp[1][1] = 1;
	pq.push({ 1,1 });
	while (!pq.empty()) {
		XY t = pq.top(); pq.pop();
		int a = MAP[t.y][t.x];
		if (a == 0) continue;

		if (t.y + a <= n) {
			if (dp[t.y + a][t.x] == 0) {
				pq.push({ t.y + a, t.x });
			}

			dp[t.y + a][t.x] += dp[t.y][t.x];
		}
		if (t.x + a <= n) {
			if (dp[t.y][t.x + a] == 0) {
				pq.push({ t.y,t.x + a });
			}

			dp[t.y][t.x + a] += dp[t.y][t.x];
		}
	}

	cout << dp[n][n];

	return 0;
}