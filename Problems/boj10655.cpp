//Problem Number : 10655
//Problem Title : 마라톤 1
//Problem Link : https://www.acmicpc.net/problem/10655

#include <iostream>
#include <vector>
#include <algorithm>

#define F first
#define S second

using namespace std;

vector<pair<int, int> > v;
vector<int> dp;

int dis(pair<int, int> a, pair<int, int> b) {
    int x = a.F - b.F;
    int y = a.S - b.S;

    if (x < 0) {
        x = -x;
    }
    if (y < 0) {
        y = -y;
    }

    return x + y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    v.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F >> v[i].S;
    }

    for (int i = 1; i < n; i++) {
        dp[i - 1] = dis(v[i], v[i - 1]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += dp[i];
    }

    int ans = sum;
    for (int i = 1; i < n - 1; i++) {
        int tmp = sum - dp[i - 1] - dp[i];

        tmp += dis(v[i - 1], v[i + 1]);

        ans = min(tmp, ans);
    }

    cout << ans;

    return 0;
}