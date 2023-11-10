//Problem Number : 9240
//Problem Title : 로버트 후드
//Problem Link : https://www.acmicpc.net/problem/9240

#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

struct point {
    long x;
    long y;
};

point p[100001];
point convex[100001];
stack<int> s;

long long sa2(point a, point b, point c)
{
    return (a.x*b.y - a.y*b.x + b.x*c.y - b.y*c.x + c.x*a.y - c.y*a.x);
}

double dis(point a, point b)
{
    return sqrt((double)((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

bool cmpXY(point a, point b)
{
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool cmpAngle(point a, point b)
{
    return sa2(p[0], a, b) > 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int mInd = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;

        if (p[mInd].x > p[i].x || (p[mInd].x == p[mInd].x && p[mInd].y > p[i].y)) {
            mInd = i;
        }
    }

    sort(p, p + n, cmpXY);
    stable_sort(p + 1, p + n, cmpAngle);

    int tmp1, tmp2;
    s.push(0);
    s.push(1);
    for (int i = 2; i < n; i++) {
        if (s.size() == 1) {
            s.push(i);
            continue;
        }

        tmp1 = s.top();
        s.pop();
        tmp2 = s.top();

        if (sa2(p[tmp2], p[tmp1], p[i]) > 0) {
            s.push(tmp1);
            s.push(i);
        }
        else {
            i--;
        }
    }

    double maxi = -1;

    int k, siz;
    k = siz = s.size();

    while (s.empty() == 0) {
        convex[--k] = p[s.top()];
        s.pop();
    }

    for (int i = 0; i < siz; i++) {
        for (int j = i + 1; j < siz; j++) {
            double d = dis(convex[i], convex[j]);

            if (maxi < d) {
                maxi = d;
            }
        }
    }

    printf("%.8lf", maxi);

    return 0;
}