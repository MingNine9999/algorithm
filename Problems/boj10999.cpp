//Problem Number : 10999
//Problem Title : 구간 합 구하기 2
//Problem Link : https://www.acmicpc.net/problem/10999

#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int n, m, k;
int siz;
vector<ll> seg, lazy;

void init(int n)
{
    for (siz = 1; siz <= n; siz <<= 1);
    seg = vector<ll> (siz * 2, 0);
    lazy = vector<ll> (siz * 2, 0);

    for (int i = 0; i < n; i++) {
        cin >> seg[i + siz];
    }
    for (int i = siz - 1; i > 0; i--) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}

void upLazy(int l, int r, int pos)
{
    if (lazy[pos]) {
        seg[pos] += (r - l + 1) * lazy[pos];

        if (l != r) {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
}

void upSeg(int s, int e, int l, int r, int pos, ll v)
{
    upLazy(l, r, pos);

    if (e < l || r < s) {
        return;
    }
    if (s <= l && r <= e) {
        lazy[pos] += v;
        upLazy(l, r, pos);
        return;
    }

    upSeg(s, e, l, (l + r) / 2, pos * 2, v);
    upSeg(s, e, (l + r) / 2 + 1, r, pos * 2 + 1, v);

    seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
}

ll getVal(int s, int e, int l, int r, int pos)
{
    upLazy(l, r, pos);

    if (e < l || r < s) {
        return 0;
    }
    if (s <= l && r <= e) {
        return seg[pos];
    }

    return getVal(s, e, l, (l + r) / 2, pos * 2) + getVal(s, e, (l + r) / 2 + 1, r, pos * 2 + 1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    init(n);
    for (int i = 0; i < m + k; i++) {
        int c, s, e, v;
        cin >> c;

        if (c == 1) {
            cin >> s >> e >> v;

            upSeg(s - 1, e - 1, 0, siz - 1, 1, v);
        }
        else {
            cin >> s >> e;

            cout << getVal(s - 1, e - 1, 0, siz - 1, 1) << '\n';
        }
    }

    return 0;
}