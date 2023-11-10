//Problem Number : 10025
//Problem Title : 게으른 백곰
//Problem Link : https://www.acmicpc.net/problem/10025

#include <iostream>

using namespace std;

int vec[1000001];
int sum[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    int g, x;
    int mx = -1;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> g >> x;
        vec[x] += g;

        if (mx < x) {
            mx = x;
        }
    }

    sum[0] = vec[0];
    for (int i = 1; i <= mx; i++) {
        sum[i] = sum[i - 1] + vec[i];
    }

    int ans = -1;
    int val;

    if (2 * k + 1 >= mx) {
        ans = sum[mx];
    }
    else {
        for (int i = k + 1; i <= mx - k; i++) {
            val = sum[i + k] - sum[i - k - 1];

            if (ans < val) {
                ans = val;
            }
        }
    }

    cout << ans;

    return 0;
}