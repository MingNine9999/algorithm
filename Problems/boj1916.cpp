//Problem Number : 1916
//Problem Title : 최소비용 구하기
//Problem Link : https://www.acmicpc.net/problem/1916

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>

#define MP make_pair

using namespace std;

int MAP[1010][1010];
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int s, e, v;
    cin >> n;
    cin >> m;

    memset(MAP, 0xFF, sizeof(MAP));
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> v;

        if (MAP[s][e] != -1) {
            MAP[s][e] = min(MAP[s][e], v);
        }
        else {
            MAP[s][e] = v;
        }
    }
    cin >> s >> e;

    dist = vector<int>(n + 1, 1234567890);
    dist[s] = 0;

    for (int i = 1; i <= n; i++) {
        pq.push(MP(dist[i], i));
    }

    while (!pq.empty()) {
        int t = pq.top().second;
        pq.pop();

        for (int i = 1; i <= n; i++) {
            if (i == t || MAP[t][i] == -1) continue;

            if (dist[i] > dist[t] + MAP[t][i]) {
                dist[i] = dist[t] + MAP[t][i];
                pq.push(MP(dist[i], i));
            }
        }
    }

    cout << dist[e];

    return 0;
}