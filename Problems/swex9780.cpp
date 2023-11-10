//Problem Number : 9780
//Problem Title : 외계인 침공
//Problem Link : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXE0gpIa3dADFAVX&categoryId=AXE0gpIa3dADFAVX&categoryType=CODE

#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

ll a[1111111];
ll dp[1111111];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TC;

	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		int n;
		ll ans = 0;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		dp[0] = a[0];
		dp[1] = max(dp[0], a[1]);
		dp[2] = max(dp[1], dp[0] + a[2]);

		for (int i = 3; i < n; i++) {
			dp[i] = max({ dp[i - 2] + a[i], dp[i - 3] + a[i], dp[i - 1] });
		}

		cout << '#' << tc << ' ' << dp[n - 1] << '\n';
	}

	return 0;
}
