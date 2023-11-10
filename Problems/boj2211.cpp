//Problem Number : 2211
//Problem Title : 네트워크 복구
//Problem Link : https://www.acmicpc.net/problem/2211

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MP make_pair
#define INF 1234567890

using namespace std;

int n, m, k;
int MAP[1010][1010];
priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
int dist[1010];
int visit[1010];


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		MAP[a][b] = c;
		MAP[b][a] = c;
	}

	dist[1] = 0;
	pq.push(MP(dist[1], 1));
	for (int i = 2; i <= n; i++) {
		dist[i] = INF;
		pq.push(MP(dist[i], i));
	}

	while (!pq.empty()) {
		pair<int, int> t = pq.top();
		pq.pop();

		for (int i = 1; i <= n; i++) {
			if (MAP[t.second][i]) {
				int s = dist[i];

				dist[i] = min(dist[i], dist[t.second] + MAP[t.second][i]);
				if (s != dist[i]) {
					visit[i] = t.second;
					pq.push(MP(dist[i], i));
				}
			}
		}
	}
	
	cout << n - 1 << "\n";
	for (int i = 2; i <= n; i++) {
		cout << i << " " << visit[i] << "\n";
	}

	return 0;
}