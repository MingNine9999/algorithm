//Problem Number : 11055
//Problem Title : 가장 큰 증가 부분 수열
//Problem Link : https://www.acmicpc.net/problem/11055

#include <iostream>
#include <algorithm>

using namespace std;

int a[1111];
int dp[1111];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		dp[i] = a[i];
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
	}

	int MAX = -1;
	for (int i = 0; i < n; i++) {
		MAX = max(MAX, dp[i]);
	}

	cout << MAX;

	return 0;
}