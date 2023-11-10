//Problem Number : 12865
//Problem Title : 평범한 배낭
//Problem Link : https://www.acmicpc.net/problem/12865

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1234567890

using ll = long long;
using namespace std;

pair<int, int> wv[111];
vector<ll> dp;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> wv[i].first >> wv[i].second;
	}
	dp = vector<ll>(2 * k, -INF);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = k; j >= wv[i].first; j--) {
			if (dp[j - wv[i].first] == -INF) continue;
		
			dp[j] = max(dp[j], dp[j - wv[i].first] + wv[i].second);
		}
	}

	ll ans = 0;

	for (int i = k; i > 0; i--) {
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}