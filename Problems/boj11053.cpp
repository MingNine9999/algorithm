//Problem Number : 11053
//Problem Title : 가장 긴 증가하는 부분 수열
//Problem Link : https://www.acmicpc.net/problem/11053

#include <iostream>
#include <vector>
#include <utility>

#define F first
#define S second

using namespace std;

vector<int> in;
vector<int> dp;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    in.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    int ans = 1;
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (in[i] > in[j] && dp[j] >= dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }

        if (dp[i] == 0) {
            dp[i] = 1;
        }
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }

    cout << ans;

    return 0;
}