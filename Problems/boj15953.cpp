//Problem Number : 15953
//Problem Title : 상금 헌터
//Problem Link : https://www.acmicpc.net/problem/15953

#include <iostream>

using namespace std;

int rw[2][6] = {{500, 300, 200, 50, 30, 10}, {512, 256, 128, 64, 32}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TC;

    cin >> TC;

    while (TC--) {
        int a, b;
        int ans = 0;
        cin >> a >> b;

        int c = 1, d = 0;
        if (a != 0) {
            while (a > c) {
                a -= c;
                c++;
            }

            if (c <= 6) {
                ans += rw[0][c - 1];
            }
        }

        c = 1;
        if (b != 0) {
            while (b > c) {
                b -= c;
                c <<= 1;
                d++;
            }

            if (d <= 5) {
                ans += rw[1][d];
            }
        }

        cout << ans * 10000 << '\n';
    }


    return 0;
}