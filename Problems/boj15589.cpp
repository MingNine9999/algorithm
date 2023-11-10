//Problem Number : 15589
//Problem Title : Lifeguards (Silver)
//Problem Link : https://www.acmicpc.net/problem/15589

#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> t[100001];
int work[100001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i].first >> t[i].second;
	}

	sort(t, t + n);

	int latest = -1;
	int minIndex = 0;

	latest = t[0].second;
	work[0] = t[0].second - t[0].first;
	for (int i = 1; i < n; i++) {
		if (t[i].second < latest) {
			work[i] = 0;
			minIndex = i;
			continue;
		}
		if (t[i].first < latest) {
			work[i - 1] -= latest - t[i].first;
			work[i] = t[i].second - latest;
		}
		else {
			work[i] = t[i].second - t[i].first;
		}

		if (latest < t[i].second) {
			latest = t[i].second;
		}

		if (work[i] < 0) {
			work[i] = 0;
		}
		if (work[i - 1] < 0) {
			work[i - 1] = 0;
		}

		if (work[minIndex] > work[i]) {
			minIndex = i;
		}

		if (work[minIndex] > work[i - 1]) {
			minIndex = i - 1;
		}
	}

	int ans = 0;
	latest = -1;
	for (int i = 0; i < n; i++) {
		if (i == minIndex) {
			continue;
		}

		if (t[i].first < latest) {
			if (t[i].second > latest) {
				ans += t[i].second - latest;
			}
		}
		else {
			ans += t[i].second - t[i].first;
		}

		if (latest < t[i].second) {
			latest = t[i].second;
		}
	}

	cout << ans;

	return 0;
}