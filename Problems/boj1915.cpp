//Problem Number : 1915
//Problem Title : 가장 큰 정사각형
//Problem Link : https://www.acmicpc.net/problem/1915

#include <iostream>

using namespace std;

char MAP[1111][1111];
int memo[1111][1111];
int MAX = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> MAP[i] + 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (MAP[i][j] == '1') {
				if (memo[i][j] == 0) {
					memo[i][j] = 1;
				}
				
				int k = memo[i][j];
				while (k != 0) {
					k = memo[i][j];

					for (int l = 0; l <= k; l++) {
						if (MAP[i + l][j + k] != '1' || MAP[i + k][j + l] != '1') {
							k = 0;
							break;
						}
					}

					for (int l = 0; l < k; l++) {
						memo[i + l][j + l]++;
					}
				}
			}

			MAX = MAX < memo[i][j] ? memo[i][j] : MAX;
		}
	}


	cout << MAX * MAX;

	return 0;
}