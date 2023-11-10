//Problem Number : 1965
//Problem Title : 상자넣기
//Problem Link : https://www.acmicpc.net/problem/1965

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
	int ans;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ans = dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
		}
	}

	cout << ans;

	return 0;
}