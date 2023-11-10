//Problem Number : 1024
//Problem Title : 수열의 합
//Problem Link : https://www.acmicpc.net/problem/1024

#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000000

using namespace std;

int dp[222][222];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l;

    cin >> n >> l;

    int a = n / l;
    int sum = 0;

    while (1) {
        a = n / l;
        for (int i = 0; i < l; i++) {
            sum += a + i;
        }

        while (sum > n) {
            a--;
            sum -= l;
        }
        if (a < 0 || l > 100) {
            a = -1;
            l = 1;
            break;
        }

        if (sum == n) {
            break;
        }
        else {
            l++;
            sum = 0;
        }
    }

    for (int i = 0; i < l; i++) {
        cout << a + i << ' ';
    }

    return 0;
}