//Problem Number : 8980
//Problem Title : None
//Problem Link : https://www.acmicpc.net/problem/8980

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int pack[2222][2222];
int truck[2222];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    int m;
    int ans = 0;
    int t = 0;

    cin >> n >> c;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        pack[a][b] += p;
    }

    int idx = 1;
    for (int i = 1; i <= n; i++) {
        ans += truck[i];
        t -= truck[i];

        for (int j = i + 1; j <= n; j++) {
            truck[j] += pack[i][j];
            t += pack[i][j];
            idx = max(idx, j);

            if (t > c) {
                for (int k = idx; k >= j; k--) {
                    if (t == c) break;
                    int g = t - c;

                    if (truck[k] >= g) {
                        truck[k] -= g;
                        t = c;
                    }
                    else {
                        t -= truck[k];
                        truck[k] = 0;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}