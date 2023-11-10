//Problem Number : 2563
//Problem Title : 색종이
//Problem Link : https://www.acmicpc.net/problem/2563

#include <iostream>

using namespace std;

int MAP[111][111];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    int x, y;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                MAP[j + x][k + y] = 1;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (MAP[i][j] == 1) {
                ans++;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}