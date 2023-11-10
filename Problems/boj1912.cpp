//Problem Number : 1912
//Problem Title : 연속합
//Problem Link : https://www.acmicpc.net/problem/1912

#include <iostream>

using namespace std;

int input[100001];
int dp[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int ans = dp[0] = input[0];
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] > 0) {
            dp[i] = input[i] + dp[i - 1];
        }
        else {
            dp[i] = input[i];
        }

        if (dp[i] > ans) {
            ans = dp[i];
        }
    }

    cout << ans;

    return 0;
}