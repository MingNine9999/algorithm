//Problem Number : 1966
//Problem Title : 프린터 큐
//Problem Link : https://www.acmicpc.net/problem/1966

#include <iostream>
#include <queue>
#include <map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;

	cin >> t;
	while (t--) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int n, m;

		cin >> n >> m;
		
		int imp;
		pair<int, int> p;
		for (int i = 0; i < n; i++) {
			cin >> imp;
			p.first = i;
			p.second = imp;
			q.push(p);
			pq.push(imp);
		}
		
		int i = 0;
		while (1) {
			if (q.front().second == pq.top()) {
				i++;
				if (q.front().first == m) {
					cout << i << "\n";
					break;
				}
				else {
					q.pop();
					pq.pop();
				}
			}
			else {
				p = q.front();
				q.pop();
				q.push(p);
			}
		}

	}

	return 0;
}