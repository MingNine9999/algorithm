//Problem Number : 16294
//Problem Title : Bee Problem
//Problem Link : https://www.acmicpc.net/problem/16294

#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

using namespace std;

int h, n, m;
char MAP[1111][2222];
bool visit[1111][2222];
vector<int> v;

const int goY[] = { 0,1,1,0,-1,-1 };
const int goX[] = { 2,1,-1,-2,-1,1 };

int dfs(int y, int x) {
	if (visit[y][x]) {
		return 0;
	}
	visit[y][x] = true;

	int ret = 1;

	for (int i = 0; i < 6; i++) {
		int yy = y + goY[i];
		int xx = x + goX[i];

		if (yy < 0 || xx < 0 || yy >= n || xx >= m || MAP[yy][xx] != '.') continue;

		ret += dfs(yy, xx);
	}

	return ret;
}

int main(void)
{
	scanf("%d%d%d", &h, &n, &m);
	getchar();

	m *= 2;
	for (int i = 0; i < n; i++) {
		fgets(MAP[i], 2220, stdin);
	}

	int r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == '.' && !visit[i][j]) {
				r = dfs(i, j);
				v.push_back(r);
			}
		}
	}

	sort(v.begin(), v.end(), greater<int>());

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (h <= 0) {
			break;
		}
		h -= v[i];
		cnt++;
	}

	printf("%d", cnt);

	return 0;
}