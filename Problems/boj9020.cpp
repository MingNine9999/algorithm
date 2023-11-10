//Problem Number : 9020
//Problem Title : 골드바흐의 추측
//Problem Link : https://www.acmicpc.net/problem/9020

#include <iostream>

using namespace std;

int a[11111];

void era(int lim)
{
    for (int i = 2; i * i <= lim; i++) {
        if (a[i] == 0) {
            for (int j = 2; i * j <= lim; j++) {
                a[i * j] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    era(10000);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q;

        for (int j = q / 2; j > 1; j--) {
            if (a[j] == 0 && a[q - j] == 0) {
                if (j > q - j) {
                    cout << q - j << ' ' << j << '\n';
                }
                else {
                    cout << j << ' ' << q - j << '\n';
                }
                break;
            }
        }
    }

    return 0;
}