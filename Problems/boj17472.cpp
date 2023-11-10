//Problem Number : 17472
//Problem Title : 다리 만들기 2 
//Problem Link : https://www.acmicpc.net/problem/17472

#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1234567890

using namespace std;

struct bridge {
	int a;
	int b;
	int v;

	bool operator<(bridge x) const {
		return v > x.v;
	}
};

int MAP[15][15];
bool visit[15][15];
int p[33];
int b[33][33];
priority_queue<bridge> pq;

const int goY[] = { 0,1,0,-1 };
const int goX[] = { 1,0,-1,0 };

void dfs(int y, int x, int c)
{
	if (visit[y][x]) {
		return;
	}

	visit[y][x] = c;
	MAP[y][x] = c;
	for (int i = 0; i < 4; i++) {
		int yy = y + goY[i];
		int xx = x + goX[i];

		if (MAP[yy][xx] == -1 || MAP[yy][xx] == 0) continue;

		dfs(yy, xx, c);
	}

	return;
}

int find(int v)
{
	if (p[v] == v) {
		return v;
	}

	return p[v] = find(p[v]);
}

bool unionSet(int a, int b)
{
	int aa = find(a);
	int bb = find(b);

	if (aa == bb) {
		return false;
	}
	p[bb] = aa;

	return true;
}

int kruscal(int c)
{
	int ret = 0;
	bridge t;

	while (!pq.empty()) {
		t = pq.top();
		pq.pop();

		if (unionSet(t.a, t.b)) {
			c--;
			ret += t.v;
		}

		if (c == 1) {
			break;
		}
	}

	if (c != 1) {
		return -1;
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	int y, x, c = 0;

	cin >> n >> m;
	for (int i = 1; i <= n || i <= m; i++) {
		MAP[0][i] = MAP[i][0] = MAP[n + 1][i] = MAP[i][m + 1] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (MAP[i][j] && visit[i][j] == false) {
				dfs(i, j, ++c);
			}
		}
	}

	for (int i = 1; i <= c; i++) {
		p[i] = i;
		for (int j = 1; j <= c; j++) {
			b[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (MAP[i][j]) {
				for (int k = 0; k < 4; k++) {
					y = i + goY[k];
					x = j + goX[k];
					int len = 0;

					while (MAP[y][x] == 0) {
						y += goY[k];
						x += goX[k];
						len++;
					}

					if (MAP[y][x] != -1 && len > 1 && MAP[i][j] != MAP[y][x]) {
						b[MAP[i][j]][MAP[y][x]] = min(b[MAP[i][j]][MAP[y][x]], len);
						b[MAP[y][x]][MAP[i][j]] = min(b[MAP[y][x]][MAP[i][j]], len);
					}
				}
			}
		}
	}
	for (int i = 1; i <= c; i++) {
		for (int j = i + 1; j <= c; j++) {
			if (b[i][j] < INF) {
				pq.push({ i,j,b[i][j] });
			}
		}
	}

	cout << kruscal(c) << endl << endl;

	return 0;
}