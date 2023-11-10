//Problem Number : 14501
//Problem Title : Επ»η
//Problem Link : https://www.acmicpc.net/problem/14501

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int time[22];
int pay[22];
int dp[22];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> pay[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		for (int j = i; j >= 1; j--) {
			if (i == j + time[j] - 1) {
				dp[i] = max(dp[i], dp[j - 1] + pay[j]);
			}
		}
	}

	cout << dp[n];

	return 0;
}