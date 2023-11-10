//Problem Number : 2178
//Problem Title : 미로 탐색
//Problem Link : https://www.acmicpc.net/problem/2178

#include <iostream>

using namespace std;

char input[102];
int map[102][102];
int visit[102][102];

int goY[4] = { 0,1,0,-1 };
int goX[4] = { 1,0,-1,0 };

void dfs(int h, int v, int r) {
	if (visit[h][v] != 0) {
		if (visit[h][v] <= r) {
			return;
		}
	}

	visit[h][v] = r;

	for (int i = 0; i < 4; i++) {
		if (map[h + goY[i]][v + goX[i]] == 1) {
			dfs(h + goY[i], v + goX[i], r + 1);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> input;
		for (int j = 1; j <= m; j++) {
			map[i][j] = input[j - 1] - '0';
		}
	}

	dfs(1, 1, 1);

	cout << visit[n][m];

	return 0;
}