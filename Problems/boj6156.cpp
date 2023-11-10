//Problem Number : 6156
//Problem Title : Cow Contest
//Problem Link : https://www.acmicpc.net/problem/6156

#include <iostream>

using namespace std;

int n, m;
int ranking[105][105];
int visit[2][105][105];

int dfs(int out, int cur, int root)
{
	int v, ret = 0;

	if (out > 0) {
		v = 0;
	}
	else {
		v = 1;
	}

	visit[v][root][cur] = 1;

	for (int i = 1; i <= n; i++) {
		if (ranking[cur][i] == out && visit[v][root][i] == 0) {
			ret += dfs(out, i, root) + 1;
		}
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0;
	int a, b;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		ranking[a][b] = 1;
		ranking[b][a] = -1;
	}

	for (int i = 1; i <= n; i++) {
		if (dfs(1, i, i) + dfs(-1, i, i) == n - 1) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}