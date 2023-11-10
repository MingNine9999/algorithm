//Problem Number : 11564
//Problem Title : 점프왕 최준민
//Problem Link : https://www.acmicpc.net/problem/11564

#include <iostream>

using ll = long long;
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll jmp, a, b;

    cin >> jmp >> a >> b;

    ll l = a / jmp;
    if (a % jmp > 0) {
        l += 1;
    }
    ll r = b / jmp;
    if (b % jmp < 0) {
        r -= 1;
    }

    cout << r - l + 1;

    return 0;
}