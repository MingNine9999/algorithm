//Problem Number : 2436
//Problem Title : 공약수
//Problem Link : https://www.acmicpc.net/problem/2436

#include <iostream>

using ll = long long;
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    int MIN = 2147483647;
    int n;

    cin >> a >> b;

    c = b / a;

    for (int i = 1; i * i <= c; i++) {
        if (c % i || gcd(i, c / i) != 1) continue;

        if (MIN > a * i + c / i * a) {
            n = i;
            MIN = a * i + c / i * a;
        }
    }

    cout << n * a << ' ' << c / n * a;

    return 0;
}