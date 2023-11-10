//Problem Number : 14289
//Problem Title : 본대 산책 3
//Problem Link : https://www.acmicpc.net/problem/14289

#include <iostream>
#include <cstring>

#define MOD(a) (a) %= 1000000007
using namespace std;
using ll = long long;

ll arr[55][55];
ll ans[55][55];
ll tmp[55][55];

void mul(ll aa[55][55], ll bb[55][55], int n)
{
    ll tt[55][55];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll t = 0;
            for (int k = 1; k <= n; k++) {
                t += aa[i][k] * bb[k][j];
                MOD(t);
            }
            tt[i][j] = t;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            aa[i][j] = tt[i][j];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, d;
    int x, y;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }

    cin >> d;
    for (int i = 1; i <= n; i++) {
        ans[i][i] = 1;
    }

    while (d) {
        if (d % 2) {
            mul(ans, arr, n);
        }
        memcpy(tmp, arr, sizeof(arr));
        mul(arr, tmp, n);
        d >>= 1;
    }

    cout << ans[1][1];

    return 0;
}
