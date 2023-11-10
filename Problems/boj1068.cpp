//Problem Number : 1068
//Problem Title : 트리
//Problem Link : https://www.acmicpc.net/problem/1068

#include <iostream>

using namespace std;

int tree[55];
int cnt[55];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    int ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        cnt[tree[i]]++;
    }
    cin >> d;
    cnt[tree[d]]--;

    for (int i = 0; i < n; i++) {
        if (cnt[i]) {
            continue;
        }

        int t = i;
        while (t != -1) {
            if (t == d) break;

            t = tree[t];
        }
        if (t == -1) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}