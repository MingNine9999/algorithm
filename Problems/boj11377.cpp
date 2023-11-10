//Problem Number : 11377
//Problem Title : 열혈강호 3
//Problem Link : https://www.acmicpc.net/problem/11377

#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int> > v;
vector<int> am;
vector<int> bm;
vector<bool> visit;

bool dfs(int s)
{
	if (visit[s]) {
		return false;
	}
	visit[s] = true;

	for (int i = 0; i < v[s].size(); i++) {
		if (bm[v[s][i]] == -1 || dfs(bm[v[s][i]])) {
			am[s] = v[s][i];
			bm[v[s][i]] = s;

			return true;
		}
	}

	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, a;

	cin >> n >> m >> k;
	v.resize(n + 1);
	am = vector<int>(n + 1, -1);
	bm = vector<int>(m + 1, -1);

	for (int i = 0; i < n; i++) {
		cin >> r;
		for (int j = 0; j < r; j++) {
			cin >> a;

			v[i].push_back(a);
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		visit = vector<bool>(n + 1, false);

		if (dfs(i)) {
			ans++;
		}
	}

	for (int i = 0; i < n && k > 0; i++) {
		visit = vector<bool>(n + 1, false);

		if (dfs(i)) {
			ans++;
			k--;
		}
	}

	cout << ans;

	return 0;
}