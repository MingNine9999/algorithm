//Problem Number : 2228
//Problem Title : 구간 나누기
//Problem Link : https://www.acmicpc.net/problem/2228

#include <iostream>
#include <algorithm>

using namespace std;

int a[111];
int dp[111][111][111];;
int n;
int MAX = -1234567890;

int dfs(int s, int e, int m) 
{
	int ret = -987654321;
	
	if (n - e < 2 * m - 1) {
		return ret;
	}
	if (m == 0) {
//	cout << s << ' ' << e << ' ' << a[e] - a[s - 1]<< endl;
		return a[e] - a[s - 1];
	}

	for (int i = e + 2; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (dp[i][j][m - 1] == 0) {
				dp[i][j][m - 1] = dfs(i, j, m - 1);
			}
			ret = max(ret, dp[i][j][m - 1]);
		}
	}

	if (ret <= -987654321) {
		return -987654321;
	}
	return ret + a[e] - a[s - 1];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	cout << dfs(0, -1, m);

	return 0;
}