//Problem Number : 11724
//Problem Title : 연결 요소의 개수
//Problem Link : https://www.acmicpc.net/problem/11724

#include <iostream>

using namespace std;

int graph[1001][1001];
bool visit[1001];

int n, m;

void dfs(int v) {
	if (visit[v]) {
		return;
	}

	visit[v] = true;
	for (int i = 1; i <= n; i++) {
		if (graph[v][i] == 1) {
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m;

	int vs, ve;
	for (int i = 0; i < m; i++) {
		cin >> vs >> ve;
		graph[vs][ve] = 1;
		graph[ve][vs] = 1;
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(i);
			ans++;
		}
	}

	cout << ans;

	return 0;
}