//Problem Number : 1946
//Problem Title : 신입 사원
//Problem Link : https://www.acmicpc.net/problem/1946

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

pair<int, int> score[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		memset(score, 0, sizeof(score));
	
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> score[i].first >> score[i].second;
		}

		sort(score, score + n);

		int ans = 0;
		int min = 1234567890;
		for (int i = 0; i < n; i++) {
			if (min > score[i].second) {
				min = score[i].second;
				ans++;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}