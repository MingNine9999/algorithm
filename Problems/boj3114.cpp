//Problem Number : 3114
//Problem Title : 사과와 바나나
//Problem Link : https://www.acmicpc.net/problem/3114

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int A[1515][1515], B[1515][1515];
int dp[1515][1515];
char input[3];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c;

	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> input;
			
			if (input[0] == 'A') {
				A[i][j] = A[i - 1][j] + atoi(&input[1]);
				B[i][j] = B[i][j - 1];
			}
			else {
				B[i][j] = B[i][j - 1] + atoi(&input[1]);
				A[i][j] = A[i - 1][j];
			}

			if (i == 1 && j == 1) {
				A[i][j] = B[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			dp[i][j] = max(
				max(dp[i][j - 1] + A[r][j - 1] - A[i][j - 1], dp[i - 1][j] + B[i - 1][c] - B[i - 1][j]),
				dp[i - 1][j - 1] + A[r][j - 1] - A[i - 1][j - 1] + B[i - 1][c] - B[i - 1][j - 1]);
		}
	}

	cout << dp[r][c];

	return 0;
}