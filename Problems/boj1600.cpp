//Problem Number : 1600
//Problem Title : 말이 되고픈 원숭이
//Problem Link : https://www.acmicpc.net/problem/1600

#include <iostream>
#include <queue>

#define MP make_pair

using namespace std;

struct YX {
    int y;
    int x;
    int v;
};

int MAP[222][222];
pair<int, int> check[222][222];
queue<YX> q;

const int goY[] = { 0,1,0,-1 };
const int goX[] = { 1,0,-1,0 };
const int knightY[] = { 1,2,2,1,-1,-2,-2,-1 };
const int knightX[] = { 2,1,-1,-2,-2,-1,1,2 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    int w, h;

    cin >> k;
    cin >> w >> h;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> MAP[i][j];
        }
    }

    check[1][1] = MP(1, k);
    q.push({1, 1, k});

    while (!q.empty()) {
        YX f = q.front(); q.pop();
        if (f.y == h && f.x == w) {
            break;
        }

        int yy, xx, vv;
        for (int i = 0; i < 4; i++) {
            yy = f.y + goY[i];
            xx = f.x + goX[i];
            vv = f.v;

            if (yy < 1 || yy > h || xx < 1 || xx > w || MAP[yy][xx] == 1) continue;

            if (check[yy][xx].first == 0 || check[yy][xx].second < vv) {
                q.push({ yy,xx,vv });
                check[yy][xx].first = check[f.y][f.x].first + 1;
                check[yy][xx].second = vv;
            }
        }

        if (f.v > 0) {
            for (int i = 0; i < 8; i++) {
                yy = f.y + knightY[i];
                xx = f.x + knightX[i];
                vv = f.v - 1;

                if (yy < 1 || yy > h || xx < 1 || xx > w || MAP[yy][xx] == 1) continue;

                if (check[yy][xx].first == 0 || check[yy][xx].second < vv) {
                    q.push({yy, xx, vv});
                    check[yy][xx].first = check[f.y][f.x].first + 1;
                    check[yy][xx].second = vv;
                }
            }
        }
    }

    cout << check[h][w].first - 1;

    return 0;
}