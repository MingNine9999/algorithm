//Problem Number : 16236
//Problem Title : 아기 상어
//Problem Link : https://www.acmicpc.net/problem/16236

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>

#define MP make_pair

using namespace std;

int MAP[22][22];
int visit[22][22];

const int goY[] = { -1,0,0,1 };
const int goX[] = { 0,-1,1,0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int sy, sx;
	int s = 2, ss = 0;
	int ans = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> MAP[i][j];

			if (MAP[i][j] == 9) {
				sy = i;
				sx = j;
				MAP[i][j] = 0;
			}
		}
	}

	while (sy != 0) {
		priority_queue<pair<int, int> ,vector<pair<int,int> >, greater<pair<int, int> > > pq;
		queue<pair<int, int> > q;

		memset(visit, 0, sizeof(visit));

		q.push(MP(sy, sx));
		visit[sy][sx] = 1;
	
		sy = 0;
		sx = 0;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int yy = y + goY[i];
				int xx = x + goX[i];

				if (yy < 1 || yy > n || xx < 1 || xx > n || visit[yy][xx]) continue;

				if (MAP[yy][xx] <= s) {
					visit[yy][xx] = visit[y][x] + 1;
					pq.push(MP(yy, xx));
				}

			}

			if (q.empty()) {
				while (!pq.empty()) {
					int yy = pq.top().first;
					int xx = pq.top().second;

					if (MAP[yy][xx] != 0 && MAP[yy][xx] < s) {
						sy = yy;
						sx = xx;
						MAP[sy][sx] = 0;
						ss++;
						ans += visit[y][x];
						if (ss == s) {
							s++;
							ss = 0;
						}

						while (!pq.empty()) {
							pq.pop();
						}
						while (!q.empty()) {
							q.pop();
						}
						break;
					}

					q.push(pq.top());
					pq.pop();
				}
			}
		}
	}

	cout << ans;

	return 0;
}