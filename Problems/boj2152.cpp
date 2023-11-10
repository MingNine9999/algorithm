//Problem Number : 2152
//Problem Title : 여행 계획 세우기
//Problem Link : https://www.acmicpc.net/problem/2152

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int n, m, s, t;
vector<int> mat[10001];
vector<int> rev[10001];
set<int> sccGraph[10001];
int visit[10001];
stack<int> st;
int group[10001];
int sccSiz[10001];
int sccNum;
int savS, savT;
int ans;

void dfs(int v)
{	
	visit[v] = 1;

	for (int i = 0; i < mat[v].size(); i++) {
		if (visit[mat[v][i]] != 1) {
			dfs(mat[v][i]);
		}
	}

	st.push(v);
}

void scc(int v)
{
	visit[v] = 2;

	for (int i = 0; i < rev[v].size(); i++) {
		if (visit[rev[v][i]] != 2) {
			scc(rev[v][i]);
		}
	}

	group[v] = sccNum;
	sccSiz[sccNum]++;

	if (v == s) {
		savS = sccNum;
	}
	if (v == t) {
		savT = sccNum;
	}
}

void dfsG(int v, int city)
{
	city += sccSiz[v];
	if (v == savT) {
		ans = max(ans, city);
		return;
	}

	visit[v] = 3;

	for (auto iter = sccGraph[v].begin(); iter != sccGraph[v].end(); iter++) {
		if (visit[*iter] != 3) {
			dfsG(*iter, city);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;

	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		mat[a].push_back(b);
		rev[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		if (visit[i]) {
			continue;
		}

		dfs(i);
	}

	while (st.empty() == 0) {
		int i = st.top();
		st.pop();

		if (visit[i] == 2) {
			continue;
		}

		scc(i);
		sccNum++;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			if (group[i] != group[mat[i][j]]) {
				sccGraph[group[i]].insert(group[mat[i][j]]);
			}
		}
	}

	dfsG(savS, 0);

	cout << ans;

	return 0;
}