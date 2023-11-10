//Problem Number : 4485
//Problem Title : ³ì»ö ¿Ê ÀÔÀº ¾Ö°¡ Á©´ÙÁö?
//Problem Link : https://www.acmicpc.net/problem/4485

#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1234567890

using namespace std;

struct dist {
	int v;
	int y;
	int x;

	bool operator< (dist a) const {
		return v > a.v;
	}
};

int MAP[155][155];
int dst[155][155];
priority_queue<dist> pq;

const int goY[] = { 0,1,0,-1 };
const int goX[] = { 1,0,-1,0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TC = 0;
	while (++TC) {
		int n;

		cin >> n;
		
		if (n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			MAP[0][i] = MAP[i][0] = MAP[n + 1][i] = MAP[i][n + 1] = INF;
			for (int j = 1; j <= n; j++) {
				cin >> MAP[i][j];
				dst[i][j] = INF;
			}
		}

		dst[1][1] = MAP[1][1];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				pq.push({ dst[i][j],i,j });
			}
		}

		while (!pq.empty()) {
			dist t = pq.top(); pq.pop();

			for (int i = 0; i < 4; i++) {
				int yy = t.y + goY[i];
				int xx = t.x + goX[i];

				if (dst[yy][xx] > MAP[yy][xx] + dst[t.y][t.x]) {
					dst[yy][xx] = MAP[yy][xx] + dst[t.y][t.x];
					pq.push({ dst[yy][xx],yy,xx });
				}
			}
		}

		cout << "Problem " << TC << ": " << dst[n][n] << '\n';
	}

	return 0;
}