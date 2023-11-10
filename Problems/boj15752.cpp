//Problem Number : 15752
//Problem Title : Hoofball
//Problem Link : https://www.acmicpc.net/problem/15752

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[111];
int c[111];
int d[111];
int b = 1;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i =0; i < n; i++) {
        cin >> a[i];
        c[i] = -1;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        if (i == n - 1 || (i != 0 && a[i] - a[i - 1] <= a[i + 1] - a[i])) {
           c[i - 1] = i;
           d[i] = -1;
       }
       else {
           c[i + 1] = i;
           d[i] = 1;
       }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == -1) {
            ans++;
        }
        else if (d[i] == 1 && d[i + 1] == -1 && ((i == 0 || d[i - 1] == -1) && (i + 1 == n - 1 ||d[i + 2] == 1))) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}