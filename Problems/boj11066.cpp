//Problem Number : 11066
//Problem Title : 파일 합치기
//Problem Link : https://www.acmicpc.net/problem/11066

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1234567890

using namespace std;

vector<int> in;
vector<int> dp[555];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TC;

	cin >> TC;
	while (TC--) {
		int k;
		
		cin >> k;
		in = vector<int>(k + 1, 0);
		for (int i = 1; i <= k; i++) {
			dp[i] = vector<int>(k + 1, INF);
			cin >> in[i];
			dp[i][i] = 0;
			in[i] += in[i - 1];
		}

		for (int i = 2; i <= k; i++) {
			dp[i - 1][i] = in[i] - in[i - 2];
		}

		for (int gap = 2; gap < k; gap++) {
			for (int i = 1; i <= k - gap; i++) {
				for (int j = 0; j < gap; j++) {
					dp[i][i + gap] = min(dp[i][i + gap], dp[i][i + j] + dp[i + j + 1][i + gap]);
				}
				dp[i][i + gap] += in[i + gap] - in[i - 1];
			}
		}

		cout << dp[1][k] << '\n';
	}

	return 0;
}