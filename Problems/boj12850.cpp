//Problem Number : 12850
//Problem Title : 본대 산책2
//Problem Link : https://www.acmicpc.net/problem/12850

#include <iostream>
#include <vector>
#include <cstring>

#define MOD(a) a %= 1000000007

using ll = long long;
using namespace std;

ll cr[8][8];
ll ans[8][8];
ll tmp[8][8];

void mul(ll a[8][8], ll b[8][8])
{
    ll tt[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ll t = 0;
            for (int k = 0; k < 8; k++) {
                t += a[i][k] * b[k][j];
                MOD(t);
            }
            tt[i][j] = t;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            a[i][j] = tt[i][j];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    cr[0][1] = cr[1][0] = 1;
    cr[0][2] = cr[2][0] = 1;
    cr[1][2] = cr[2][1] = 1;
    cr[1][3] = cr[3][1] = 1;
    cr[2][3] = cr[3][2] = 1;
    cr[2][4] = cr[4][2] = 1;
    cr[3][4] = cr[4][3] = 1;
    cr[3][5] = cr[5][3] = 1;
    cr[4][5] = cr[5][4] = 1;
    cr[4][7] = cr[7][4] = 1;
    cr[5][6] = cr[6][5] = 1;
    cr[6][7] = cr[7][6] = 1;

    for (int i = 0; i < 8; i++) {
        ans[i][i] = 1;
    }

    while (n) {
        if (n % 2) {
            mul(ans, cr);
        }
        memcpy(tmp, cr, sizeof(cr));
        mul(cr, tmp);
        n >>= 1;
    }

    cout << ans[0][0];

    return 0;
}