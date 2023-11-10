//Problem Number : 1866
//Problem Title : 택배
//Problem Link : https://www.acmicpc.net/problem/1866

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v;
int dp[3010];
int dp2[3010];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	int t, h;

	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}	
	cin >> t >> h;

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + v[i] * t;
		memset(dp2, 0, v.size());
		for (int j = i; j >= 0; j--) {
			dp2[j] = dp2[j + 1] + (v[(j + i + 1) / 2] - v[j]);
			dp[i] = min(dp[i], dp[j - 1] + dp2[j] * t + h);
		}
	}

	cout << dp[n];

	return 0;
}
