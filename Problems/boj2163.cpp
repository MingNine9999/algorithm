//Problem Number : 2163
//Problem Title : 초콜릿 자르기
//Problem Link : https://www.acmicpc.net/problem/2163

#include <iostream>

using namespace std;

int dp[301][301];

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 2; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] + 1;	
	}
	
	for (int i = 2; i <= m; i++) {
		dp[n][i] = dp[n][i - 1] + dp[n][1] + 1;
	}
	

	cout << dp[n][m];

	return 0;
}