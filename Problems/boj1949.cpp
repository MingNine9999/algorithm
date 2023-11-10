//Problem Number : 1949
//Problem Title : 우수 마을
//Problem Link : https://www.acmicpc.net/problem/1949

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<vector<int> > g;
int dp[10001][2];
vector<int> visit;

void dfs(int x)
{
    visit[x] = 1;
    dp[x][1] += v[x];

    for (int i = 0; i < g[x].size(); i++) {
        if (visit[g[x][i]] == 0) {
            dfs(g[x][i]);
            dp[x][1] += dp[g[x][i]][0];
            dp[x][0] += max(dp[g[x][i]][0], dp[g[x][i]][1]);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    v.resize(n + 1);
    g.resize(n + 1);
    visit = vector<int> (n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);
    
    cout << max(dp[1][0], dp[1][1]);

    return 0;
}