//Problem Number : 10868
//Problem Title : 최솟값
//Problem Link : https://www.acmicpc.net/problem/10868

#include <iostream>
#include <vector>

#define INF 1234567890

using namespace std;

int siz;
vector<int> seg;

void init(int n)
{
    for (siz = 1; siz <= n; siz <<= 1);

    seg = vector<int> (siz * 2 + 1, INF);
    for (int i = 0; i < n; i++) {
        cin >> seg[siz + i];
    }

    for (int i = siz - 1; i > 0; i--) {
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
}

int getVal(int s, int e)
{
    int ret = INF;
    int l = s + siz - 1;
    int r = e + siz - 1;

    while (l < r) {
        if (l % 2 == 1) {
            ret = min(ret, seg[l++]);
        }
        if (r % 2 == 0) {
            ret = min(ret, seg[r--]);
        }
        l >>= 1;
        r >>= 1;
    }
    if (l == r) {
        ret = min(ret, seg[l]);
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << getVal(s, e) << '\n';
    }


    return 0;
}