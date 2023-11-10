//Problem Number : 1707
//Problem Title : 이분 그래프
//Problem Link : https://www.acmicpc.net/problem/1707

#include <iostream>
#include <vector>

using namespace std;

int V, E;
vector<vector<int> > GP;
vector<int> check;

bool dfs(int v, int g)
{
    bool ret = true;

    if (check[v]) {
        if (g != check[v]) {
            return false;
        }
        return true;
    }

    check[v] = g;

    for (int i = 0; i < GP[v].size(); i++) {
        ret = dfs(GP[v][i], g * -1);

        if (ret == false) {
            return ret;
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TC;

    cin >> TC;

    while (TC--) {
        cin >> V >> E;

        GP.clear();
        GP.resize(V + 1);
        check = vector<int>(V + 1, 0);
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;

            GP[a].push_back(b);
            GP[b].push_back(a);
        }

        bool ans = true;
        for (int i = 1; i <= V && ans; i++) {
            if (check[i] == 0) {
                ans = dfs(i, 1);
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}