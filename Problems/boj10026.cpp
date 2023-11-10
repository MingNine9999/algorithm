//Problem Number : 10026
//Problem Title : 적록색약
//Problem Link : https://www.acmicpc.net/problem/10026

#include <iostream>

using namespace std;

char map[102][102];
int visit1[102][102];
int visit2[102][102];

int goY[4] = { 0,1,0,-1 };
int goX[4] = { 1,0,-1,0 };

int n;

void dfs1(int h, int v) {
	if (visit1[h][v]) {
		return;
	}
	visit1[h][v] = 1;

	for (int i = 0; i < 4; i++) {
		if (h + goY[i] >= 0 && h + goY[i] < n && v + goX[i] >= 0 && v + goX[i] < n) {
			if (map[h][v] == map[h + goY[i]][v + goX[i]]) {
				dfs1(h + goY[i], v + goX[i]);
			}
		}
	}
}

void dfs2(int h, int v) {
	if (visit2[h][v]) {
		return;
	}
	visit2[h][v] = 1;

	for (int i = 0; i < 4; i++) {
		if (h + goY[i] >= 0 && h + goY[i] < n && v + goX[i] >= 0 && v + goX[i] < n) {
			if (map[h][v] == map[h + goY[i]][v + goX[i]]) {
				dfs2(h + goY[i], v + goX[i]);
			}
			else if (map[h][v] == 'R' && map[h + goY[i]][v + goX[i]] == 'G') {
				dfs2(h + goY[i], v + goX[i]);
			}
			else if (map[h][v] == 'G' && map[h + goY[i]][v + goX[i]] == 'R') {
				dfs2(h + goY[i], v + goX[i]);
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int ans1 = 0;
	for (int h = 0; h < n; h++) {
		for (int v = 0; v < n; v++) {
			if (visit1[h][v] == 0) {
				dfs1(h, v);
				ans1++;
			}
		}
	}

	int ans2 = 0;
	for (int h = 0; h < n; h++) {
		for (int v = 0; v < n; v++) {
			if (visit2[h][v] == 0) {
				dfs2(h, v);
				ans2++;
			}
		}
	}


	cout << ans1 << " " << ans2;


	return 0;
}