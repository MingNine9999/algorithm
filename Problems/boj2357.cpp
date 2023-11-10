//Problem Number : 2357
//Problem Title : 최솟값과 최댓값
//Problem Link : https://www.acmicpc.net/problem/2357

#include <iostream>
#include <vector>

#define INF 1234567890
using namespace std;

typedef long long ll;

int n, m;
int siz;
vector<int> seg;
vector<int> ssg;

void init(int n)
{
    for (siz = 1; siz <= n; siz <<= 1);

    seg = vector<int> (siz * 2 + 1, INF);
    ssg = vector<int> (siz * 2 + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> seg[i + siz];
        ssg[i + siz] = seg[i + siz];

    }
    for (int i = siz - 1; i > 0; i--) {
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
        ssg[i] = max(ssg[i * 2], ssg[i * 2 + 1]);
    }
}

int getVal(int l, int r, int s, int e, int pos, int mode)
{
    if (l > e || r < s) {
        if (mode == 1)
            return INF;
        else
            return -1;
    }
    else if (s <= l && r <= e) {
        if (mode == 1)
            return seg[pos];
        else
            return ssg[pos];
    }
    else {
        if (mode == 1)
        return min(
                getVal(l, (l + r) / 2, s, e, pos * 2, mode),
                getVal((l + r) / 2 + 1, r, s, e, pos * 2 + 1, mode)
        );
        else
            return max(
                    getVal(l, (l + r) / 2, s, e, pos * 2, mode),
                    getVal((l + r) / 2 + 1, r, s, e, pos * 2 + 1, mode)
                    );
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << getVal(0, siz - 1, s - 1, e - 1, 1, 1) << ' ' << getVal(0, siz - 1, s - 1, e - 1, 1, 2) << '\n';
    }
    
    return 0;
}