//Problem Number : 2042
//Problem Title : 구간 합 구하기
//Problem Link : https://www.acmicpc.net/problem/2042

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> a, b;
int n, m, k;
int siz;

void init(int x)
{
    for (siz = 1; siz < x; siz <<= 1);
}

void up(int pos, ll x)
{
    while (pos <= siz) {
        b[pos] += x;
        pos += (pos & -pos);
    }
}

ll sum(int pos)
{
    ll ret = 0;

    while (pos) {
        ret += b[pos];
        pos -= (pos & -pos);
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll c, p, v;

    cin >> n >> m >> k;
    init(n);
    a.resize(siz + 1);
    b = vector<ll> (siz + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        up(i, a[i]);
    }

    for (int i = 0; i < m + k; i++) {
        cin >> c >> p >> v;
        if (c == 1) {
            up(p, v - a[p]);
            a[p] = v;
        }
        else {
            cout << sum(v) - sum(p - 1) << '\n';
        }
    }

    return 0;
}