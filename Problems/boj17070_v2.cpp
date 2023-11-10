#include <iostream>
#include <algorithm>

using namespace std;

int MAP[22][22];
int dp[22][22][3];

const int preY[] = { -1,-1,0 };
const int preX[] = { 0,-1,-1 };
const int pre[] = { 2,3,2 };
const int preDir[][3] = { { 0,1 }, { 0,1,2 }, { 1,2 } };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> MAP[i][j];
		}
	}

	dp[1][2][2] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (MAP[i][j] == 1) continue;

			for (int k = 0; k < 3; k++) {
				int y = i + preY[k];
				int x = j + preX[k];

				if (y < 1 || y > n || x < 1 || x > n) continue;
				if (k == 1 && (MAP[i][j - 1] == 1 || MAP[i - 1][j] == 1)) continue;

				for (int l = 0; l < pre[k]; l++) {
					dp[i][j][k] += dp[y][x][preDir[k][l]];
				}
			}
		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];

	return 0;
}
