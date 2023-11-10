//Problem Number : 1629
//Problem Title : 곱셈
//Problem Link : https://www.acmicpc.net/problem/1629

#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

vector<ll> dp;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c;

    cin >> a >> b >> c;

    a %= c;

    ll ans = 1;
    while (b) {
        if (b % 2) {
            ans = ans * a % c;
        }
        a = a * a % c;
        b >>= 1;
    }

    cout << ans;

    return 0;
}