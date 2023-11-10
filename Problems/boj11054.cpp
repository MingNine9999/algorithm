//Problem Number : 11054
//Problem Title : 가장 긴 바이토닉 부분 수열
//Problem Link : https://www.acmicpc.net/problem/11054

#include <iostream>
#include <algorithm>

using namespace std;

int a[1111];
int dp[1111];
int dpr[1111];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dp[0] = dpr[n - 1] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = dpr[n - 1 - i] = 1;

		for (int j = i - 1; j >= 0; j--) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		for (int j = n - i; j < n; j++) {
			if (a[n - 1 - i] > a[j]) {
				dpr[n - 1 - i] = max(dpr[n - 1 - i], dpr[j] + 1);
			}
		}
	}

	int MAX = -1;
	for (int i = 0; i < n; i++) {
		MAX = max(MAX, dp[i] + dpr[i] - 1);
	}

	cout << MAX;

	return 0;
}