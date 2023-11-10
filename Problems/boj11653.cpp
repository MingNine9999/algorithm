//Problem Number : 11653
//Problem Title : 소인수분해
//Problem Link : https://www.acmicpc.net/problem/11653

#include <iostream>

using namespace std;

int isPrime[11111111];

void eratos(void)
{
    isPrime[0] = isPrime[1] = 1;
    for (int i = 2; i * i <= 10000000; i++) {
        if (isPrime[i]) continue;

        for (int j = 2; i * j <= 10000000; j++) {
            isPrime[i * j] = 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    int i = 2;
    while (n / i) {
        if (isPrime[i]) {
            i++;
            continue;
        }
        if (n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
        else {
            i++;
        }
    }

    return 0;
}