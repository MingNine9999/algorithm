//Problem Number : 15803
//Problem Title : PLAYERJINAH’S BOTTLEGROUNDS
//Problem Link : https://www.acmicpc.net/problem/15803

#include <iostream>

using namespace std;

struct point {
    int x;
    int y;
};

point p[5];

int sineA(point a, point b, point c)
{
    int k = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);

    if (k == 0) {
        return 0;
    }
    else {
        return 1;
    }

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++) {
        cin >> p[i].x >> p[i].y;
    }

    if (sineA(p[0], p[1], p[2]) == 0) {
        cout << "WHERE IS MY CHICKEN?";
    }
    else {
        cout << "WINNER WINNER CHICKEN DINNER!";
    }

    return 0;
}