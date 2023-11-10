//Problem Number : 14464
//Problem Title : 소가 길을 건너간 이유 4
//Problem Link : https://www.acmicpc.net/problem/14464

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int chicken[20001];
pair<int, int> cow[20001];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, n;

	cin >> c >> n;
	for (int i = 0; i < c; i++) {
		cin >> chicken[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cow[i].first >> cow[i].second;
	}

	sort(chicken, chicken + c);
	sort(cow, cow + n, cmp);

	int ans = 0;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < n; j++) {
			if (cow[j].first <= chicken[i] && chicken[i] <= cow[j].second) {
				ans++;
				cow[j].first = 1234567890;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}