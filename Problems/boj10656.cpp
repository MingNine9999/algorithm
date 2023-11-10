//Problem Number : 10656
//Problem Title : 십자말풀이
//Problem Link : https://www.acmicpc.net/problem/10656

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char MAP[55][55];
vector<pair<int, int> > ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (MAP[i][j] == '.') {
                int check = 0;
                if (MAP[i - 1][j] == '#' || i == 1) {
                    if (MAP[i + 1][j] == '.' && MAP[i + 2][j] == '.') {
                        check = 1;
                    }
                }

                if (MAP[i][j - 1] == '#' || j == 1) {
                    if (MAP[i][j + 1] == '.' && MAP[i][j + 2] == '.') {
                        check = 1;
                    }
                }

                if (check == 1) {
                    ans.push_back(make_pair(i, j));
                }
            }
        }
    }

    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " <<ans[i].second << "\n";
    }


    return 0;
}