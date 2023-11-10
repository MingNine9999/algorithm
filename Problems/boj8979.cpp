//Problem Number : 8979
//Problem Title : 올림픽
//Problem Link : https://www.acmicpc.net/problem/8979

#include <iostream>

using namespace std;

int na[1111][4];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    int a, b;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> na[a][1] >> na[a][2] >> na[a][3];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (na[i][1] > na[k][1]) {
            ans++;
        }
        else if (na[i][1] == na[k][1] && na[i][2] > na[k][2]) {
            ans++;
        }
        else if (na[i][1] == na[k][1] && na[i][2] == na[k][2] && na[i][3] > na[k][3]) {
            ans++;
        }
    }

    cout << ans + 1;

    return 0;
}