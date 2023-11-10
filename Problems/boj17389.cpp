//Problem Number : 17389
//Problem Title : 보너스 점수
//Problem Link : https://www.acmicpc.net/problem/17389

#include <iostream>

#define X 'X'
#define O 'O'

using namespace std;

char a[11111];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    cin >> a + 1;

    int b = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == O) {
            ans += i + b;
            b++;
        }
        else {
            b = 0;
        }
    }

    cout << ans;

    return 0;
}