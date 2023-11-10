//Problem Number : 13160
//Problem Title : 최대 클리크 구하기
//Problem Link : https://www.acmicpc.net/problem/13160

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
pair<int, int> p[300100];
int numLine[600100];
int arr[600100];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        numLine[i * 2] = p[i].first;
        numLine[i * 2 + 1] = p[i].second;

    }

    sort(numLine, numLine + n * 2);

    for (int i = 0; i < n; i++) {
        int a = (int)(lower_bound(numLine, numLine + n * 2, p[i].first) - numLine);
        int b = (int)(upper_bound(numLine, numLine + n * 2, p[i].second) - numLine);

        arr[a]++;
        arr[b]--;
    }

    int ans = 0, now = 0, idx = 0;
    for (int i = 0; i < n * 2; i++) {
        now += arr[i];
        if (ans < now) {
            ans = now;
            idx = i;
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        if (p[i].first <= numLine[idx] && numLine[idx] <= p[i].second) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}