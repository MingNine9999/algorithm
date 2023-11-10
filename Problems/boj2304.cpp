//Problem Number : 2304
//Problem Title : 창고 다각형
//Problem Link : https://www.acmicpc.net/problem/2304

#include <iostream>

using namespace std;

int col[1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int l, h;
    int maxIndex = 0, lastIndex = -1;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> h;

        col[l] = h;

        if (col[maxIndex] < h) {
            maxIndex = l;
        }
        if (lastIndex < l) {
            lastIndex = l;
        }
    }

    int ans = 0;

    int m = 0;
    for (int i = 0; i < maxIndex; i++) {
        if (col[i] > m) {
            m = col[i];
        }
        ans += m;
    }
    m = 0;
    for (int i = lastIndex; i > maxIndex; i--) {
        if (col[i] > m) {
            m = col[i];
        }

        ans += m;
    }

    ans += col[maxIndex];

    cout << ans;

    return 0;
}