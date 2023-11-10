//Problem Number : 6159
//Problem Title : 코스튬 파티
//Problem Link : https://www.acmicpc.net/problem/6159

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int cow[20001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    int *pos;
    int ans = 0;

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }

    sort(cow, cow + n);

    for (int i = 0; cow[i] <= s / 2; i++) {
        pos = lower_bound(cow, cow + n, s - cow[i] + 1);

        ans += (int)(pos - cow) - i - 1;
    }

    cout << ans;

    return 0;
}