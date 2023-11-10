//Problem Number : 2644
//Problem Title : 촌수계산
//Problem Link : https://www.acmicpc.net/problem/2644

#include <iostream>

using namespace std;

int rel[101][101];
bool visit[101];
int n;
int a, b;
int m;

int dfs(int v, int level) {
	if (v == b) return level;

	if (visit[v]) {
		return 0;
	}

	visit[v] = true;
	for (int i = 1; i <= n; i++) {
		if (rel[v][i] == 1) {
			int check = dfs(i, level + 1);
			if (check) {
				return check;
			}
		}
	}
	
	return 0;
}

int main() {

	cin >> n;
	cin >> a >> b;
	cin >> m;
	
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		rel[x][y] = 1;
		rel[y][x] = 1;
	}
	
	int ans = dfs(a, 0);

	if (ans) {
		cout << ans;
	}
	else {
		cout << -1;
	}

	return 0;
}