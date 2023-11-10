//Problem Number : 17027
//Problem Title : Shell Game
//Problem Link : https://www.acmicpc.net/problem/17027

#include <iostream>
#include <algorithm>

using namespace std;

int cup[4];
int com[111][3];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int maxAns = -1;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> com[i][0] >> com[i][1] >> com[i][2];
    }

    for (int i = 1; i <= 3; i++) {
        int ans = 0;
        cup[i] = 1;

        for (int j = 0; j < n; j++) {
            int t = cup[com[j][0]];
            cup[com[j][0]] = cup[com[j][1]];
            cup[com[j][1]] = t;

            if (cup[com[j][2]] == 1) {
                ans++;
            }
        }

        maxAns = max(maxAns, ans);


        for (int j = 1; j <= 3; j++) {
            cup[j] = 0;
        }
    }

    cout << maxAns;

    return 0;
}