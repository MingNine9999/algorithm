//Problem Number : 2699
//Problem Title : 격자점 컨벡스헐
//Problem Link : https://www.acmicpc.net/problem/2699

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct point {
    int y;
    int x;
};

point arr[55];

bool cmp(point a, point b)
{
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y > b.y;
}

int ccw(point a, point b, point c)
{
    int ret = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);

    if (ret == 0) return 0;
    return ret > 0 ? 1 : -1;
}

bool cmp2(point a, point b)
{
    return ccw(arr[0], a, b) == -1 ? true : false;
}



int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TC;

    cin >> TC;
    while (TC--) {
        int n;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr[i].x >> arr[i].y;
        }

        sort(arr, arr + n, cmp);
        stable_sort(arr + 1, arr + n, cmp2);

        stack<point> s, t;

        for (int i = 0; i < n; i++) {
            if (s.size() < 2) {
                s.push(arr[i]);
                continue;
            }

            point t2 = s.top(); s.pop();
            point t1 = s.top();

            if (ccw(t1, t2, arr[i]) == -1) {
                s.push(t2);
                s.push(arr[i]);
            }
            else {
                i--;
            }
        }

        while (!s.empty()) {
            t.push(s.top());
            s.pop();
        }

        cout << t.size() << '\n';
        while (!t.empty()) {
            cout << t.top().x << ' ' << t.top().y << '\n';
            t.pop();
        }
    }

    return 0;
}