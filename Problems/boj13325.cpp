//Problem Number : 13325
//Problem Title : None
//Problem Link : https://www.acmicpc.net/problem/13325

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> node;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int ans = 0;

    cin >> n;
    int k = 2 << n;
    k -= 2;
    node = vector<int> (k + 2, 0);
    v = vector<int> (k + 2, 0);

    for (int i = 2; i <= k + 1; i++) {
        cin >> v[i];
        ans += v[i];
    }

    for (int i = n; i > 0; i--) {
        int s = 1 << i;
        int e = 1 << (i + 1);
        for (int j = s; j < e; j += 2) {
            int l = node[j] + v[j];
            int r = node[j + 1] + v[j + 1];

            node[j / 2] = max(l, r);
            ans += (l > r ? l - r : r - l);
        }
    }

    cout << ans;

    return 0;
}