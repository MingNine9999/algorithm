//Problem Number : 1325
//Problem Title : 효율적인 해킹
//Problem Link : https://www.acmicpc.net/problem/1325

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> MAP[11111];
vector<int> par[11111];
vector<int> check;
vector<int> ans;

int dfs(int v)
{
    if (check[v]) {
        return 0;
    }
    check[v] = 1;
    int ret = 0;

    for (int i = 0; i < MAP[v].size(); i++) {
        ret += dfs(MAP[v][i]);
    }

    return ret + 1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int a, b;
    int MAX = -1;

    cin >> n >> m;
    ans = vector<int> (n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        MAP[b].push_back(a);
        par[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
       // if (par[i].size() == 0) {
            check = vector<int> (n + 1, 0);

            ans[i] = dfs(i);
            MAX = max(MAX, ans[i]);
      //  }
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] == MAX) {
            cout << i << ' ';
        }
    }

    return 0;
}