//Problem Number : 17070
//Problem Title : 파이프 옮기기 1 
//Problem Link : https://www.acmicpc.net/problem/17070

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int MAP[22][22];

const int goY[] = { 0,1,1 };
const int goX[] = { 1,1,0 };
const int nn[] = { -1,0,1 };

int dfs(int y, int x, int s)
{
	if (y == n && x == n) {
		return 1;
	}

	int ret = 0;

	for (int i = 0; i < 3; i++) {
		int ns = s + nn[i];
		if (ns < 0 || ns > 2) continue;
		if (ns == 1 && (MAP[y][x + 1] || MAP[y + 1][x])) continue;

		int yy = y + goY[ns];
		int xx = x + goX[ns];

		if (yy < 1 || yy > n || xx < 1 || xx > n || MAP[yy][xx] == 1) continue;
		ret += dfs(yy, xx, ns);
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> MAP[i][j];
		}
	}

	cout << dfs(1, 2, 0);

	return 0;
}