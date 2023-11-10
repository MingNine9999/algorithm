//Problem Number : 1978
//Problem Title : 소수 찾기
//Problem Link : https://www.acmicpc.net/problem/1978

#include <iostream>

using namespace std;

bool isprime[1111];

void eratos(int n)
{
    isprime[1] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (isprime[i] == 0) {
            for (int j = 2; i * j <= n; j++) {
                isprime[i * j] = 1;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int ans = 0;
    eratos(1000);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        ans += isprime[a] == 0 ? 1 : 0;
    }

    cout << ans;

    return 0;
}