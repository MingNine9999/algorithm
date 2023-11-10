//Problem Number : 14500
//Problem Title : 테트로미노
//Problem Link : https://www.acmicpc.net/problem/14500

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int MAP[555][555];
int visit[555][555];

const int goY[] = { 0,1,0,-1 };
const int goX[] = { 1,0,-1,0 };

int dfs(int y, int x, int lv)
{
	if (visit[y][x]) {
		return -1234567890;
	}
	if (lv == 3) {
		return MAP[y][x];
	}

	visit[y][x] = 1;

	int MAX = 0;

	if (lv == 0) {
		MAX = MAP[y][x + 1] + MAP[y + 1][x] + MAP[y + 1][x + 1];

		int tmp = 0;
		
		for (int i = 0; i < 4; i++) {
			int yy = y + goY[i];
			int xx = x + goX[i];

			tmp += MAP[yy][xx];
		}

		if (tmp != -1) {
			for (int i = 0; i < 4; i++) {
				int yy = y + goY[i];
				int xx = x + goX[i];

				MAX = max(MAX, tmp - MAP[yy][xx]);
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		int yy = y + goY[i];
		int xx = x + goX[i];

		if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;

		MAX = max(MAX, dfs(yy, xx, lv + 1));		
	}

	visit[y][x] = 0;

	return MAX + MAP[y][x];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, dfs(i, j, 0));
		}
	}

	cout << ans;

	return 0;
}