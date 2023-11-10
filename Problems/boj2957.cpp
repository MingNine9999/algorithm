//Problem Number : 2957
//Problem Title : None
//Problem Link : https://www.acmicpc.net/problem/2957

#include <iostream>
#include <algorithm>
#include <set>

using ll = long long;
using namespace std;

set<int> s;
ll num[333333];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll c = 0;
    int a;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;

        auto l = s.lower_bound(a);
        auto u = s.upper_bound(a);

        if (!s.empty()) {
            if (l == s.begin()) {
                num[a] = num[*l] + 1;
            }
            else {
                l--;
                if (u == s.end()) {
                    num[a] = num[*l] + 1;
                }
                else {
                    num[a] = max(num[*l], num[*u]) + 1;
                }
            }
        }

        s.insert(a);
        c += num[a];

        cout << c << '\n';
    }


    return 0;
}