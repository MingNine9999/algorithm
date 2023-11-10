//Problem Number : 1413
//Problem Title : 박스 안의 열쇠
//Problem Link : https://www.acmicpc.net/problem/1413

#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

ll dp[21][21];

ll gcd(ll a, ll b)
{
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;

    cin >> a >> b;

    for (int i = 1; i <= a; i++) {
        dp[i][i] = 1;
    }
    ll fac = 1;
    for (int i = 2; i <= a; i++) {
        fac *= i;
    }

    for (int i = 2; i <= a; i++) {
        for (int j = 1; j <= a && j <= b; j++) {
            dp[i][j] = (i - 1) * dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    ll c = 0;
    for (int i = 1; i <= b; i++) {
       c += dp[a][i];
    }
    ll g = gcd(fac, c);
    
    cout << c / g << "/" << fac / g;

    return 0;
}