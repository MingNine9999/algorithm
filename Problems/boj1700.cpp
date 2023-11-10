//Problem Number : 1700
//Problem Title : 멀티탭 스케줄링
//Problem Link : https://www.acmicpc.net/problem/1700

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int use[101];
int multi[101];
priority_queue<int, vector<int>, greater<int> > pq[101];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		pq[i].push(1234567890);
		cin >> use[i];
		pq[use[i]].push(i);
	}

	int ans = 0;
	int tab = 0;

	for (int i = 0; i < k; i++) {
		pq[use[i]].pop();
		int check = 0;
		for (int j = 0; j < tab; j++) {
			if (multi[j] == use[i]) {
				check = 1;
				break;
			}
		}
		if (check) {
			continue;
		}

		if (tab < n) {
			multi[tab] = use[i];
			tab++;
		}
		else {
			int late = 0;
			for (int j = 1; j < tab; j++) {
				if (pq[multi[late]].top() < pq[multi[j]].top()) {
					late = j;
				}
			}
			multi[late] = use[i];
			ans++;
		}
	}

	cout << ans;

	return 0;
}