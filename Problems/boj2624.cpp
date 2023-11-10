//Problem Number : 2624
//Problem Title : 동전 바꿔주기
//Problem Link : https://www.acmicpc.net/problem/2624

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> p[101];
int dp[10001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, k;

	cin >> t;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> p[i].first >> p[i].second;
	}

	int m = 0;
	dp[0] = 1;

	//sort(p, p + k);

	for (int i = k - 1; i >= 0; i--) {
		for (int l = m; l >= 0; l--) {
			if (dp[l] == 0) {
				continue;
			}

			for (int j = p[i].second; j > 0; j--) {
				if (p[i].first * j + l > t) {
					continue;
				}

				dp[p[i].first * j + l] += dp[l];
			}
		}

		m = min(t, p[i].first * p[i].second + m);
	}

	cout << dp[t];

	return 0;
}
