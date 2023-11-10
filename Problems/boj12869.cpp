//Problem Number : 12869
//Problem Title : 뮤탈리스크
//Problem Link : https://www.acmicpc.net/problem/12869

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct hp {
    int a;
    int b;
    int c;
};

int visit[66][66][66];
int scv[3];
int mutal[][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};
queue<hp> bfs;
queue<hp> tmp;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> scv[i];
    }

    hp fir = {scv[0], scv[1], scv[2]};
    int ans = 0;
    int check = 0;

    bfs.push(fir);
    while (bfs.empty() == 0) {
        while (bfs.empty() == 0) {
            tmp.push(bfs.front());
            if (bfs.front().a + bfs.front().b + bfs.front().c == 0) {
                check = 1;
                break;
            }
            bfs.pop();
        }
        if (check) {
            break;
        }

        ans++;
        while (tmp.empty() == 0) {
            hp f = tmp.front(); tmp.pop();
            for (int i = 0; i < 6; i++) {
                hp p;
                p.a = max(f.a - mutal[i][0], 0);
                p.b = max(f.b - mutal[i][1], 0);
                p.c = max(f.c - mutal[i][2], 0);
                if (visit[p.a][p.b][p.c] == 1) {
                    continue;
                }

                bfs.push(p);
                visit[p.a][p.b][p.c] = 1;
            }
        }
    }

    cout << ans;

    return 0;
}