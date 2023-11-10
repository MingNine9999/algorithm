//Problem Number : 2206
//Problem Title : 벽 부수고 이동하기
//Problem Link : https://www.acmicpc.net/problem/2206

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct point {
	int y;
	int x;
	int v;
};
int n, m;
char MAP[1111][1111];
int visit[2][1111][1111];
queue<point> q;

const int goX[] = { 1,0,-1,0 };
const int goY[] = { 0,1,0,-1 };

int bfs(void)
{
	int ret = 0;

	q.push({ 0,0,0 });
	visit[0][n - 1][m - 1] = visit[1][n - 1][m - 1] = 1234567890;
	visit[0][0][0] = 1;

	while (!q.empty()) {
		point f = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = f.y + goY[i];
			int xx = f.x + goX[i];
			int vv = f.v;

			if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
			if (MAP[yy][xx] == '1' && vv == 0) {
				vv++;
				if (visit[vv][yy][xx] == 0 || visit[vv][yy][xx] > visit[f.v][f.y][f.x] + 1) {
					visit[vv][yy][xx] = visit[f.v][f.y][f.x] + 1;
					q.push({ yy,xx,vv });
				}
			}
			else if (MAP[yy][xx] == '0' && (visit[vv][yy][xx] == 0 || visit[vv][yy][xx] > visit[f.v][f.y][f.x] + 1)) {
				visit[vv][yy][xx] = visit[f.v][f.y][f.x] + 1;
				q.push({ yy,xx,vv });
			}
		}
	}
	
	ret = min(visit[0][n - 1][m - 1], visit[1][n - 1][m - 1]);

	return (ret == 1234567890 ? -1 : ret);
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

	cout << bfs();

	return 0;
}