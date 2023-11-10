//Problem Number : 1967
//Problem Title : 트리의 지름
//Problem Link : https://www.acmicpc.net/problem/1967

#include <iostream>
#include <algorithm>
#include <vector>

#define MP make_pair

using namespace std;

vector<pair<int, int> > MAP[11111];
int check[11111];

void dfs(int v, int w)
{
    if (check[v]) {
        return;
    }

    check[v] = w;

    for (int i = 0; i < MAP[v].size(); i++) {
        dfs(MAP[v][i].first, w + MAP[v][i].second);
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int a, b, c;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;

        MAP[a].push_back(MP(b, c));
        MAP[b].push_back(MP(a, c));
    }

    dfs(1, 0);

    int MAX = -1, idx;
    for (int i = 1; i <= n; i++) {
        if (MAX < check[i]) {
            MAX = check[i];
            idx = i;
        }
        check[i] = 0;
    }

    dfs(idx, 0);
    cout << *max_element(check + 1, check + n + 1);


    return 0;
}