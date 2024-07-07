//Problem Number : 2239
//Problem Title : 스도쿠
//Problem Link : https://www.acmicpc.net/problem/2239

#include <iostream>

using namespace std;

char in[11][11];
int mat[11][11];
bool r[11][11];
bool c[11][11];
bool s[11][11];
bool solved;

int square(int x, int y)
{
    return (x / 3) * 3 + (y / 3);
}

bool setting(int x, int y)
{
    if (x >= 9) {
        return true;
    }

    if (y >= 9) {
        return setting(x + 1, 0);
    }

    if (mat[x][y] != 0) {
        return setting(x, y + 1);
    }
    int sq = square(x, y);

    for (int v = 1; v <= 9; v++) {
        if (!r[x][v] && !c[y][v] && !s[sq][v]) {
            mat[x][y] = v;

            r[x][v] = true;
            c[y][v] = true;
            s[sq][v] = true;

            if (setting(x, y + 1)) {
                return true;
            }

            mat[x][y] = 0;

            r[x][v] = false;
            c[y][v] = false;
            s[sq][v] = false;
        }
    }

    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> in[i][j];
            mat[i][j] = in[i][j] - '0';

            if (mat[i][j] != 0)
            {
                r[i][mat[i][j]] = true;
                c[j][mat[i][j]] = true;
                s[square(i, j)][mat[i][j]] = true;
            }
        }
    }

    setting(0, 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << mat[i][j];
        }
        cout << '\n';
    }

    return 0;
}
