//Problem Number : 14746
//Problem Title : Closest Pair
//Problem Link : https://www.acmicpc.net/problem/14746

#include <iostream>
#include <algorithm>

using namespace std;

int P[500500];
int Q[500500];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int py, qy;
    int MIN = 1234567890;
    int cnt = 0;

    cin >> n >> m;
    cin >> py >> qy;
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> Q[i];
    }

    sort(P, P + n);
    sort(Q, Q + m);
    int c = 0;

    for (int i = 0, j = 0; i < n && j < m;) {
        int a = P[i] - Q[j];

        if (a < 0) {
            c = 1;
            a = -a;
        }
        else {
            c = 0;
        }

        if (a < MIN) {
            cnt = 1;
            MIN = a;
        }
        else if (a == MIN) {
            cnt++;
        }

        if (c == 1) {
            i++;
        }
        else {
            j++;
        }
    }

    int y = py - qy > 0 ? py - qy : qy - py;

    cout << MIN + y << ' ' << cnt;

    return 0;
}