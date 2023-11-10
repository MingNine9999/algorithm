//Problem Number : 2162
//Problem Title : 선분 그룹
//Problem Link : https://www.acmicpc.net/problem/2162

#include <iostream>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

struct point {
    ll x;
    ll y;
};

pair<point, point> line[3005];
int parent[3005];
int dep[3005];
int siz[3005];
int g;

int ccw(point a, point b, point c)
{
    ll sine = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);

    if (sine > 0) {
        return 1;
    }
    else if (sine < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

int cross(pair<point, point> a, pair<point, point> b)
{
    int check1 = ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
    int check2 = ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);

    if (check1 == 0 && check2 == 0) {
        if (a.first.x == a.second.x) {
            return !(a.first.y > b.second.y || a.second.y < b.first.y);
        }
        else {
            return !(a.first.x > b.second.x || a.second.x < b.first.x);
        }
    }

    return check1 <= 0 && check2 <= 0;
}

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionset(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return;
    }

    if (dep[x] < dep[y]) {
        parent[x] = y;
        siz[y] += siz[x];
    }
    else {
        parent[y] = x;
        siz[x] += siz[y];
    }

    if (dep[x] == dep[y]) {
        dep[x]++;
    }

    g--;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    point t;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> line[i].first.x >> line[i].first.y >> line[i].second.x >> line[i].second.y;

        if (line[i].first.x > line[i].second.x
        || (line[i].first.x == line[i].second.x && line[i].first.y > line[i].second.y)) {
            swap(line[i].first, line[i].second);
        }
    }
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        siz[i] = 1;
    }
    g = n;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cross(line[i], line[j])) {
                unionset(i, j);
            }
        }
    }

    int maxg = -1;
    for (int i = 0; i < n; i++) {
        maxg = max(maxg, siz[i]);
    }

    cout << g << "\n" << maxg;

    return 0;
}