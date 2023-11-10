//Problem Number : 12026
//Problem Title : BOJ 거리
//Problem Link : https://www.acmicpc.net/problem/12026

#include <iostream>
#include <algorithm>

#define INF 1234567890
#define PREV(a) (a - 1) >= 0 ? (a - 1) : 2

using namespace std;

const char in[] = {'B', 'O', 'J'};
char arr[1111];
int dp[1111];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int k = 1;

    cin >> n;
    cin >> arr;

    fill(dp + 1, dp + n, INF);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i] == in[j]) {
                k = j;
                break;
            }
        }
        k = PREV(k);

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] == in[k]) {
                dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
            }
        }
    }

    if (dp[n - 1] == INF) {
        cout << -1;
    }
    else {
        cout << dp[n - 1];
    }

    return 0;
}
