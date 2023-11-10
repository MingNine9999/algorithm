//Problem Number : 6086
//Problem Title : 최대 유량
//Problem Link : https://www.acmicpc.net/problem/6086

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

#define aa 'a'
#define AA 'A'
#define GAP 26

using namespace std;

int n;
int g[55][55];
int lv[55];
int f[55][55];
vector<set<int> > al;
const int S = 0, E = 25;

int bfs()
{
    queue<int> q;
    fill(lv, lv + 55, -1);

    lv[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int fr = q.front(); q.pop();

        for (auto it = al[fr].begin(); it != al[fr].end(); it++) {
            if (lv[*it] != -1 || g[fr][*it] == f[fr][*it]) continue;

            q.push(*it);
            lv[*it] = lv[fr] + 1;
        }
    }

    if (lv[E] == -1) {
        return 0;
    }
    return 1;
}

int dfs(int v, int flow)
{
    int ret = 0;

    if (v == E) {
        return flow;
    }

    for (auto it = al[v].begin(); it != al[v].end(); it++) {
        if (lv[*it] - lv[v] != 1) continue;

        ret = dfs(*it, min(flow, g[v][*it] - f[v][*it]));

        if (ret != 0) {
            f[v][*it] += ret;
            f[*it][v] -= ret;
            return ret;
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char s, e;
    int ss, ee;
    int val;

    cin >> n;
    al.resize(55);
    for (int i = 0; i < n; i++) {
        cin >> s >> e >> val;

        if (s >= aa) s -= aa - GAP;
        else s -= AA;
        if (e >= aa) e -= aa - GAP;
        else e -= AA;

        ss = (int)s;
        ee = (int)e;

        g[ss][ee] += val;
        al[ss].insert(ee);
        g[ee][ss] += val;
        al[ee].insert(ss);
    }

    int ans = 0;
    while (1) {
        if (!bfs()) break;
        ans += dfs(S, 1234567890);
    }

    cout << ans;

    return 0;
}