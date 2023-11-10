//Problem Number : 17127
//Problem Title : 벚꽃이 정보섬에 피어난 이유
//Problem Link : https://www.acmicpc.net/problem/17127

#include <iostream>

using namespace std;

int n;
int arr[11];
int dp[11][11];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int sum = 0;
	int maxVal = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i][i] = arr[i];
	}

	for (int gap = 1; gap < n; gap++) {
		for (int i = 0; i + gap < n; i++) {
			dp[i][i + gap] = dp[i][i + gap - 1] * arr[i + gap];
		}
	}

	for (int i = 0; i < n - 3; i++) {
		for (int j = i + 1; j < n - 2; j++) {
			for (int k = j + 1; k < n - 1; k++) {
				sum = dp[0][i] + dp[i + 1][j] + dp[j + 1][k] + dp[k + 1][n - 1];
				if (maxVal < sum) {
					maxVal = sum;
				}
			}
		}
	}

	cout << maxVal;

	return 0;
}