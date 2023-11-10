//Problem Number : 1708
//Problem Title : 볼록 껍질
//Problem Link : https://www.acmicpc.net/problem/1708

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
using ll = long long;

struct point {
    ll x;
    ll y;
};

int n;
point p[222222];

int sa(point a, point b, point c) {
    ll v = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);

    if (v < 0) {
        return -1;
    }
    else if (v > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

bool cmp(point a, point b)
{
    int ret = sa(p[0], a, b);

    if (ret == 0) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
    return ret > 0;
}

void swap(point &a, point &b)
{
    point t = a;
    a = b;
    b = t;
}

ll dis(point a, point b)
{
    ll x = a.x - b.x;
    ll y = a.y - b.y;

    return x * x + y * y;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
  //  cin >> tc;

    while (tc--) {
        int MIN = 0;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;

            if (p[MIN].x > p[i].x || (p[MIN].x == p[i].x && p[MIN].y > p[i].y)) {
                MIN = i;
            }
        }

        swap(p[0], p[MIN]);
        sort(p + 1, p + n, cmp);

        deque<int> dq;
        for (int i = 0; i < n; i++) {
            if (dq.size() < 2) {
                dq.push_back(i);
                continue;
            }

            int t1, t2, r;
            t2 = dq.back(); dq.pop_back();
            t1 = dq.back();

            r = sa(p[t1], p[t2], p[i]);
            if (r > 0) {
                dq.push_back(t2);
                dq.push_back(i);
            }
            else {
                i--;
            }
        }
        cout << dq.size();

        /*ll d = 0, t;
        int a, b, k = 0;
        int ansA, ansB;
        a = dq[k];

        for (int i = 1; k < dq.size(); i++) {
            i %= dq.size();

            b = dq[i];

            t = dis(p[a], p[b]);
            if (d <= t) {
                d = t;
                ansA = a;
                ansB = b;
            }
            else {
                a = dq[++k];
                i--;
            }
        }

        printf("%lld %lld %lld %lld\n", p[ansA].x, p[ansA].y, p[ansB].x, p[ansB].y);*/
    }

    return 0;
}