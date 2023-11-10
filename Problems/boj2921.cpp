//Problem Number : 2921
//Problem Title : µµ¹Ì³ë 
//Problem Link : https://www.acmicpc.net/problem/2921

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1111];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i * (i + 1);
		dp[i] += dp[i] / 2;
		dp[i] += dp[i - 1];
	}

	cout << dp[n];

	return 0;
}