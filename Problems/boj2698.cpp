//Problem Number : 2698
//Problem Title : 인접한 비트의 개수
//Problem Link : https://www.acmicpc.net/problem/2698

#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][101][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[1][0][0] = 1;
    dp[1][0][1] = 1;

    for (int i = 2; i < 101; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
        }
    }

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, k;

        cin >> n >> k;

        cout << dp[n][k][0] + dp[n][k][1] << "\n";
    }

    return 0;
}