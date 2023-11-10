//Problem Number : 17370
//Problem Title : 육각형 우리 속의 개미
//Problem Link : https://www.acmicpc.net/problem/17370

#include <iostream>
#include <algorithm>

using namespace std;

int visit[111][111];

const int goY[] = { 0,1,0,-1 };
const int goX[] = { 1,0,-1,0 };

int dfs(int y, int x, int preY, int preX, int n)
{
	cout << y << ' ' << x << endl;
	if (visit[y][x]) {
		if (n == 0) {
			return 1;
		}
		return 0;
	}
	if (n == 0) {
		return 0;
	}

	int ret = 0;

	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		if (y % 2 == x % 2 && i == 3) {
			continue;
		}
		else if (y % 2 != x % 2 && i == 1) {
			continue;
		}
		int yy = y + goY[i];
		int xx = x + goX[i];
		
		if (yy == preY && xx == preX) continue;

		ret += dfs(yy, xx, y, x, n - 1);
	}

	visit[y][x] = 0;

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	visit[51][50] = 1;
	cout << dfs(50, 50, 51, 50, n);

	return 0;
}