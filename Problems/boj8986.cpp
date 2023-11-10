//Problem Number : 8986
//Problem Title : None
//Problem Link : https://www.acmicpc.net/problem/8986

#include <iostream>
#include <algorithm>

#define ABS(a) ((a) > 0 ? (a) : -(a))

using namespace std;
using ll = long long;

int n;
ll a[111111];

ll check(ll dis)
{
    ll move1 = 0, move2 = 0;
    for (ll i = 1; i < n; i++) {
        move1 += ABS(a[i] - i * dis);
        move2 += ABS(a[i] - i * (dis + 1));
    }

    return (move1 < move2 ? move1 : -1);
}

ll parametric(ll l, ll r)
{
    ll ret = 0;
    ll mid;

    while (l < r) {
        mid = (l + r) / 2;

        ll tmp = check(mid);

        if (tmp == -1) {
            l = mid + 1;
        }
        else {
            r = mid;
            ret = tmp;
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << parametric(1, a[n - 1]);

    return 0;
}