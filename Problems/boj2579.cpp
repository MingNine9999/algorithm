//Problem Number : 2579
//Problem Title : 계단 오르기
//Problem Link : https://www.acmicpc.net/problem/2579

#include <iostream>

using namespace std;

int max(int a, int b) {
	return (a) > (b) ? (a) : (b);
}

int n;
int stair[303];
int memo[303][3];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}

	memo[n - 1][0] = stair[n];
	memo[n - 1][2] = stair[n] + stair[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		memo[i][0] = max(memo[i + 1][1], memo[i + 1][2]);
		memo[i][1] = memo[i + 1][0] + stair[i];
		memo[i][2] = memo[i + 1][1] + stair[i];
	}

	cout << max(memo[0][0], memo[0][1]);

	return 0;
}