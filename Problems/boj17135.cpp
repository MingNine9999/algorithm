//Problem Number : 17135
//Problem Title : 캐슬 디펜스
//Problem Link : https://www.acmicpc.net/problem/17135

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int board[17][17];
int tmpBoard[17][17];
int archerSet[3001][3];
pair<int, int> p[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, d;
    int cnt = 0;
    int ans = 0;

    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= m - 2; i++) {
        for (int j = i + 1; j <= m - 1; j++) {
            for (int k = j + 1; k <= m; k++) {
                archerSet[cnt][0] = i;
                archerSet[cnt][1] = j;
                archerSet[cnt][2] = k;
                cnt++;
            }
        }
    }

    for (int s = 0; s < cnt; s++) {
        memcpy(tmpBoard, board, sizeof(board));
        int tmp = 0;
        for (int i = n + 1; i > 1; i--) {
            int c = 0, check;
            for (int a = 0; a < 3; a++) {
                int  j = archerSet[s][a];
                check = 0;
                    for (int k = 1; k <= d && check == 0; k++) {
                        for (int l = 1; l < k && check == 0; l++) {
                            if (i - l > 0 && j - k + l > 0 && tmpBoard[i - l][j - k + l]) {
                                p[c].first = i - l;
                                p[c].second = j - k + l;
                                check = 1;
                            }
                        }
                        for (int l = k; l > 0 && check == 0; l--) {
                            if (i - l > 0 && j + k - l <= m && tmpBoard[i - l][j + k - l]) {
                                p[c].first = i - l;
                                p[c].second = j + k - l;
                                check = 1;
                            }
                        }

                    }
                    c++;
                }

                for (int k = 0; k < c; k++) {
                    if (tmpBoard[p[k].first][p[k].second]) {
                        tmpBoard[p[k].first][p[k].second] = 0;
                        tmp++;
                    }
                    p[k].first = 0;
                    p[k].second = 0;
                }

                if (tmp > ans) {
                    ans = tmp;
                }
            }
        }


    cout << ans;

    return 0;
}