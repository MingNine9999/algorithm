//Problem Number : 2167
//Problem Title : 2차원 배열의 합
//Problem Link : https://www.acmicpc.net/problem/2167

#include <iostream>
#include <algorithm>

using namespace std;

int MAP[333][333];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int in;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> in;

            MAP[i][j] = MAP[i - 1][j] + MAP[i][j - 1] + in - MAP[i - 1][j - 1];
        }
    }

    int T;

    cin >> T;
    while (T--) {
        int y1, x1, y2, x2;

        cin >> y1 >> x1 >> y2 >> x2;

        cout << MAP[y2][x2] - MAP[y2][x1 - 1] - MAP[y1 - 1][x2] + MAP[y1 - 1][x1 - 1] << "\n";
    }

    return 0;
}