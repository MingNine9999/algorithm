//Problem Number : 2590
//Problem Title : 색종이
//Problem Link : https://www.acmicpc.net/problem/2590

#include <iostream>

using namespace std;

int sq[11];
int ans;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 6; i++) {
        cin >> sq[i];
    }

    int a = 36;
    ans += sq[6];

    ans += sq[5];

    sq[1] -= sq[5] * 11;

    ans += sq[4];

    a *= sq[4];
    a -= sq[4] * 4 * 4;

    if (a > sq[2] * 2 * 2) {
        a -= sq[2] * 2 * 2;
        sq[2] = 0;
        sq[1] -= a;
    }
    else if (a > 0){
        sq[2] -= a / 4;
    }

    ans += sq[3] / 4;
    if (sq[3] % 4) {
        a = sq[3] % 4;
        ans += 1;

        if (sq[2] - (7 - 2 * a) <= 0) {
            sq[1] -= 36 - (a * 3 * 3) - (sq[2] * 2 * 2);
            sq[2] = 0;
        }
        else {
            sq[2] -= 7 - 2 * a;
            sq[1] -= 36 - (a * 3 * 3) - ((7 - 2 * a) * 2 * 2);
        }
    }

    ans += sq[2] / 9;
    if (sq[2] % 9) {
        a = sq[2] % 9;
        ans += 1;

        sq[1] -= 36 - a * 2 * 2;
    }

    if (sq[1] > 0) {
        ans += sq[1] / 36;
        if (sq[1] % 36) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}