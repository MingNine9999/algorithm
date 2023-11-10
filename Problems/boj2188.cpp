//Problem Number : 2188
//Problem Title : 축사 배정
//Problem Link : https://www.acmicpc.net/problem/2188

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> cow[222];
int visit[222];
vector<int> a, b;

int dfs(int v)
{
    visit[v] = 1;
    for (int i = 0; i < cow[v].size(); i++) {
        int st = cow[v][i];
        if (b[st] == 0 || (!visit[b[st]] && dfs(b[st]))) {
            a[v] = st;
            b[st] = v;
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, in;
    cin >> n >> m;
    a.resize(n + 1);
    b.resize(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> in;
            cow[i].push_back(in);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            fill(visit, visit + 222, 0);

            if (dfs(i)) ans++;
        }
    }

    cout << ans;

    return 0;
}
