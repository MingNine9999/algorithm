//Problem Number : 1937
//Problem Title : 욕심쟁이 판다
//Problem Link : https://www.acmicpc.net/problem/1937

#include <iostream>

using namespace std;

const int goY[] = { 0,1,0,-1 };
const int goX[] = { 1,0,-1,0 };

int mat[505][505];
int dp[505][505];

int dfs(int y, int x)
{
	if (dp[y][x] != 0) {
		return dp[y][x];
	}

	int ret = 0;
	int life = 0;
	for (int i = 0; i < 4; i++) {
		if (mat[y + goY[i]][x + goX[i]] > mat[y][x]) {
			life = dfs(y + goY[i], x + goX[i]);
			if (ret < life) {
				ret = life;
			}
		}
	}

	dp[y][x] = ++ret;

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}

	int maxLife = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (maxLife < dfs(i, j)) {
				maxLife = dp[i][j];
			}
		}
	}

	cout << maxLife;

	return 0;
}