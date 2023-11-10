//Problem Number : 14466
//Problem Title : 소가 길을 건너간 이유 6
//Problem Link : https://www.acmicpc.net/problem/14466

#include <iostream>
#include <vector>

using namespace std;

int n, k, r;
int gr[110][110][4];
int visit[110][110];
pair<int, int> cow[101];
int arr[110][110];
int restCow;

const int goY[] = { 0,1,0,-1 };
const int goX[] = { 1,0,-1,0 };

int dfs(int y, int x) {
	int ret = 0;
	int check[4] = { 0 };

	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		if (gr[y][x][i] == 0 && visit[y + goY[i]][x + goX[i]] == 0) {
			ret += dfs(y + goY[i], x + goX[i]);
		}
	}

	if (arr[y][x]) {
		restCow--;
	}

	return ret + arr[y][x];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d;
	int m1, m2;

	cin >> n >> k >> r;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> c >> d;

		m1 = a - c;
		m2 = b - d;

		if (m1) {
			if (m1 < 0) {
				gr[a][b][1] = 1;
				gr[c][d][3] = 1;
			}
			else {
				gr[a][b][3] = 1;
				gr[c][d][1] = 1;
			}
		}
		else {
			if (m2 < 0) {
				gr[a][b][0] = 1;
				gr[c][d][2] = 1;
			}
			else {
				gr[a][b][2] = 1;
				gr[c][d][0] = 1;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> cow[i].first >> cow[i].second;
		arr[cow[i].first][cow[i].second] = 1;
	}
	restCow = k;

	for (int i = 1; i <= n; i++) {
		visit[i][0] = 1;
		visit[0][i] = 1;
		visit[i][n + 1] = 1;
		visit[n + 1][i] = 1;
	}

	int cur = 0;
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] != 1) {
				cur = dfs(i, j);

				ans += cur * restCow;
			}
		}
	}

	cout << ans;

	return 0;
}