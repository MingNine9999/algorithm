//Problem Number : 11725
//Problem Title : 트리의 부모 찾기
//Problem Link : https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> tree[100001];
int par[100001];

void dfs(int v, int p) {
	if (par[v] != 0) {
		return;
	}

	par[v] = p;

	for (int i = 0; i < tree[v].size(); i++) {
		dfs(tree[v][i], v);
	}
}

int main() {
	cin >> n;

	int vs, ve;
	for (int i = 0; i < n - 1; i++) {
		cin >> vs >> ve;
		tree[vs].push_back(ve);
		tree[ve].push_back(vs);
	}

	dfs(1, 1);

	for (int i = 2; i <= n; i++) {
		cout << par[i] << "\n";
	}

	return 0;
}