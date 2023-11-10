//Problem Number : 2567
//Problem Title : 색종이 - 2
//Problem Link : https://www.acmicpc.net/problem/2567

#include <iostream>

using namespace std;

const int goY[] = { 0,1,0,-1 };
const int goX[] = { 1,0,-1,0 };

int MAP[111][111];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int y, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                MAP[y + j][x + k] = 1;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (MAP[i][j]) {
                for (int k = 0; k < 4; k++) {
                    if (MAP[i + goY[k]][j + goX[k]] == 0) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}