//Problem Number : 1167
//Problem Title : 트리의 지름
//Problem Link : https://www.acmicpc.net/problem/1167

#include <iostream>
#include <algorithm>
#include <vector>

#define MP make_pair

using namespace std;

int n;
vector<vector<pair<int, int> > > MAP;
vector<int> visit;
int MAX = -1;
int last;

void dfs(int s, int dis, int vis)
{
	int e;

	visit[s] = vis;

	if (MAX < dis) {
		MAX = dis;
		last = s;
	}

	for (int i = 0; i < MAP[s].size(); i++) {
		e = MAP[s][i].first;

		if (visit[e] != vis) {
			dfs(e, dis + MAP[s][i].second, vis);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s, e, v;

	cin >> n;
	MAP.resize(n + 1);
	visit.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> s;

		while (1) {
			cin >> e;
			if (e == -1) break;

			cin >> v;

			MAP[s].push_back(MP(e, v));
		}
	}

	dfs(1, 0, 1);
	MAX = -1;
	dfs(last, 0, 2);
	
	cout << MAX;

	return 0;
}