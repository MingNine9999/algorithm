//Problem Number : 2156
//Problem Title : 포도주 시식
//Problem Link : https://www.acmicpc.net/problem/2156

#include <iostream>
#include <algorithm>

using namespace std;

int podo[10001];
int dp[10001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> podo[i];
    }

    dp[0][1] = podo[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = dp[i - 1][0] + podo[i];
        dp[i][2] = dp[i - 1][1] + podo[i];
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

    return 0;
}