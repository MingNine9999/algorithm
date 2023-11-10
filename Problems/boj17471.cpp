//Problem Number : 17471
//Problem Title : 게리맨더링 
//Problem Link : https://www.acmicpc.net/problem/17471

#include <iostream>
#include <algorithm>

#define INF 1234567890
#define ABS(a) ((a) >= 0 ? (a) : -(a))

using namespace std;

int n;
int people[11];
int MAP[11][11];
int check[11];
int visit[11];
int con[11];
int MIN = INF;
int total;

void dfs(int v, int m)
{
	if (visit[v] != -1) {
		return;
	}

	visit[v] = m;
	for (int i = 0; i < con[v]; i++) {
		if (check[MAP[v][i]] == m) {
			dfs(MAP[v][i], m);
		}
	}

	if (v == 1) {
		int c = 0;
		for (int i = 2; i <= n; i++) {
			if (check[i] == m && visit[i] == -1) {
				return;
			}
			if (check[i] != m) {
				c = i;
			}
		}

		if (c != 0) {
			dfs(c, check[c]);
		}
	}

	return;
}

void pick(int v, int p) 
{
	if (v > n) {
		int tmp = total - p;
		int c = 0;

		if (ABS(tmp - p) < MIN) {
			for (int i = 1; i <= n; i++) {
				visit[i] = -1;
			}

			dfs(1, check[1]);
			for (int i = 1; i <= n; i++) {
				if (visit[i] == -1) {
					c = -1;
				}
			}

			if (c == 0) {
				MIN = ABS(tmp - p);
			}
		}

		return;
	}

	check[v] = 0;
	pick(v + 1, p);
	check[v] = 1;
	pick(v + 1, p + people[v]);

	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
		total += people[i];
	}
	MIN = total;

	con[0] = n;
	for (int i = 1; i <= n; i++) {
		cin >> con[i];
		for (int j = 0; j < con[i]; j++) {
			cin >> MAP[i][j];
		}
		MAP[0][i - 1] = i;
	}
	
	pick(1, 0);

	if (MIN == total) {
		cout << -1;
	}
	else {
		cout << MIN;
	}

	return 0;
}