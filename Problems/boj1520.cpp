//Problem Number : 1520
//Problem Title : 내리막 길
//Problem Link : https://www.acmicpc.net/problem/1520

#include <iostream>
#include <queue>

using namespace std;

struct point {
    int y;
    int x;
    int v;

    bool operator <(point a) const{
        return v < a.v;
    }
};

priority_queue<point> pq;

int MAP[555][555];
int visit[555][555];

const int goY[] = { 0,1,0,-1 };
const int goX[] = { 1,0,-1,0 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> MAP[i][j];
        }
    }

    visit[0][0] = 1;
    pq.push({0, 0, MAP[0][0]});

    while (!pq.empty()) {
        point t = pq.top(); pq.pop();

        if (t.y == m - 1 && t.x == n - 1) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            point tt = {t.y + goY[i], t.x + goX[i], 0};
            tt.v = MAP[tt.y][tt.x];

            if (tt.v < t.v) {
                if (visit[tt.y][tt.x] == 0) {
                    pq.push(tt);
                }
                visit[tt.y][tt.x] += visit[t.y][t.x];
            }
        }
    }
    
    cout << visit[m - 1][n - 1];

    return 0;
}