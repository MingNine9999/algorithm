//Problem Number : 14503
//Problem Title : 로봇 청소기
//Problem Link : https://www.acmicpc.net/problem/14503

#include <iostream>

using namespace std;

int MAP[55][55];
int visit[55][55];

const int goX[] = { 0,1,0,-1 };
const int goY[] = { -1,0,1,0 };

int dfs(int y, int x, int d)
{
    int yy, xx;

    for (int i = 1; i <= 4; i++) {
        yy = y + goY[(d - i + 4) % 4];
        xx = x + goX[(d - i + 4) % 4];

        if (MAP[yy][xx] == 0 && visit[yy][xx] == 0) {
            visit[yy][xx] = 1;
            return dfs(yy, xx, (d - i + 4) % 4) + 1;
        }
    }

    yy = y + goY[(d + 2) % 4];
    xx = x + goX[(d + 2) % 4];
    if (MAP[yy][xx] == 0) {
        return dfs(yy, xx, d);
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int y, x, d;

    cin >> n >> m;
    cin >> y >> x >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> MAP[i][j];
        }
    }

    visit[y][x] = 1;
    cout << dfs(y, x, d);

    return 0;
}