//Problem Number : 2749
//Problem Title : 피보나치 수 3
//Problem Link : https://www.acmicpc.net/problem/2749

#include <iostream>
#include <cstring>

#define MOD(a) a %= 1000000

using namespace std;
using ll = long long;

ll arr[2][2];
ll ans[2][2];
ll tmp[2][2];

void mul(ll a[2][2], ll b[2][2])
{
    ll tt[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ll t = 0;
            for (int k = 0; k < 2; k++) {
                t += a[i][k] * b[k][j];
                MOD(t);
            }
            tt[i][j] = t;
        }
    }

    memcpy(a, tt, sizeof(arr));
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;

    cin >> n;
    arr[0][1] = arr[1][0] = arr[1][1] = 1;
    ans[0][0] = ans[1][1] = 1;

    while (n) {
        if (n % 2) {
            mul(ans, arr);
        }
        memcpy(tmp, arr, sizeof(arr));
        mul(arr, tmp);
        n >>= 1;
    }

    cout << ans[0][1];

    return 0;
}