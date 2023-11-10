//Problem Number : 11758
//Problem Title : CCW
//Problem Link : https://www.acmicpc.net/problem/11758

#include <iostream>

using namespace std;

struct point{
    int x;
    int y;
};

int sa(point a, point b, point c)
{
    return (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    point p[3];
    for (int i = 0; i < 3; i++) {
        cin >> p[i].x >> p[i].y;
    }

    int ans = sa(p[0], p[1], p[2]);

    if (ans == 0) {
        cout << 0;
    }
    else if (ans < 0) {
        cout << -1;
    }
    else {
        cout << 1;
    }

    return 0;
}