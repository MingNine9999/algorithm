//Problem Number : 2234
//Problem Title : 성곽
//Problem Link : https://www.acmicpc.net/problem/2234

#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

struct point {
	int y;
	int x;
};

int wall[55][55];
int visit[55][55];
int gr[2525][2525];
int sizRoom[2525];
queue<point> q;

const int goY[] = { 0,-1,0,1 };
const int goX[] = { -1,0,1,0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> wall[i][j];
		}
	}
	int room = 0;
	int c = 0;
	int maxRoom = 0;
	int maxSum = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] == 0) {
				room++;

				point p = { i,j };
				q.push(p);
				visit[p.y][p.x] = room;
				while (q.empty() == 0) {
					point f = q.front();

					for (int g = 0; g < 4;g++) {
						if ((wall[f.y][f.x] >> g) % 2 == 0 && visit[f.y + goY[g]][f.x + goX[g]] == 0) {
							point t = { f.y + goY[g], f.x + goX[g] };
							visit[t.y][t.x] = room;
							q.push(t);
						}
					}

					q.pop();
				}

			}
			
		}
	}

	point p;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			sizRoom[visit[i][j]]++;
			for (int g = 0; g < 4; g++) {
				if (visit[i + goY[g]][j + goX[g]] != 0 && visit[i][j] != visit[i + goY[g]][j + goX[g]]) {
					gr[visit[i][j]][visit[i + goY[g]][j + goX[g]]] = 1;
					gr[visit[i + goY[g]][j + goX[g]]][visit[i][j]] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= room; i++) {
		for (int j = i + 1; j <= room; j++) {
			if (gr[i][j] == 1) {
				maxSum = max(maxSum, sizRoom[i] + sizRoom[j]);
			}
		}

		maxRoom = max(maxRoom, sizRoom[i]);
	}

	cout << room << "\n" << maxRoom << "\n" << maxSum;

	return 0;
}