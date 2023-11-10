//Problem Number : 10830
//Problem Title : 행렬 제곱
//Problem Link : https://www.acmicpc.net/problem/10830

#include <iostream>
#include <vector>
#include <cstring>

#define MOD(a) a %= 1000

using namespace std;
using ll = long long;

int n;
ll b;
ll arr[5][5];
ll ans[5][5];
ll tmp[5][5];

void mul(ll a[5][5], ll b[5][5])
{
    ll tt[5][5];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll t = 0;
            for (int k = 0; k < n; k++) {
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

    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
        ans[i][i] = 1;
    }

    while (b) {
        if (b % 2) {
            mul(ans, arr);
        }
        memcpy(tmp, arr, sizeof(arr));
        mul(arr, tmp);
        b >>= 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}