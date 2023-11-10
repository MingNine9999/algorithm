//Problem Number : 1260
//Problem Title : DFS와 BFS
//Problem Link : https://www.acmicpc.net/problem/1260

#include <iostream>
#include <queue>

using namespace std;

int graph[1001][1001];
bool visitD[1001];
bool visitB[1001];
int n, m, s;

queue<int> bfs;

void dfs(int v) {
	if (visitD[v]) {
		return;
	}
	visitD[v] = true;

	cout << v << " ";
	for (int i = 1; i <= n; i++) {
		if (graph[v][i] == 1) {
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m >> s;

	int vs, ve;
	for (int i = 0; i < m; i++) {
		cin >> vs >> ve;
		graph[vs][ve] = 1;
		graph[ve][vs] = 1;
	}

	dfs(s);

	cout << "\n";

	

	bfs.push(s);
	visitB[s] = true;
	while (!bfs.empty()) {
		vs = bfs.front();
		for (int i = 1; i <= n; i++) {
			if (graph[vs][i] == 1) {
				if (visitB[i] == false) {
					bfs.push(i);
					visitB[i] = true;
				}
			}
		}
		bfs.pop();
		cout << vs << " ";
	}

	return 0;
}