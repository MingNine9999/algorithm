//Problem Number : 1939
//Problem Title : 중량제한 
//Problem Link : https://www.acmicpc.net/problem/1939

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1234567890

using namespace std;

vector<pair<int, int> > MAP[11111];
int check[11111];

int n, m;
int s, d;

int dfs(int v, int w)
{
	int ret = 0;
	if (check[v]) return ret;
	if (v == d) return 1;
	check[v] = 1;

	for (int i = 0; i < MAP[v].size(); i++) {
		if (MAP[v][i].second < w) continue;

		ret = dfs(MAP[v][i].first, w);
		if (ret) break;
	}

	return ret;
}

int pms(int l, int r)
{
	while (l < r) {
		int mid = (l + r + 1) / 2;
		
		fill(check, check + n + 1, 0);
		if (dfs(s, mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}

	return l;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int MIN = INF, MAX = 0;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, v, ac = 0, bc = 0;

		cin >> a >> b >> v;

		MAP[a].push_back({ b,v });
		MAP[b].push_back({ a,v });

		MAX = max(MAX, v);
	}
	cin >> s >> d;

	for (int i = 0; i < MAP[s].size(); i++) {
		if (MAP[s][i].first == d) {
			MIN = min(MIN, MAP[s][i].second);
			break;
		}
	}
	if (MIN == INF) {
		MIN = 1;
	}

	cout << pms(MIN, MAX);

	return 0;
}