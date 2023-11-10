//Problem Number : 11049
//Problem Title : 행렬 곱셈 순서
//Problem Link : https://www.acmicpc.net/problem/11049

#include <iostream>
#include <algorithm>

#define MP make_pair
#define INF 1234567890

using namespace std;

int cmm[555][555];
pair<int, int> m[555][555];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cmm[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> m[i][i].first >> m[i][i].second;
    }

    for (int i = 1; i < n; i++) {
        cmm[i - 1][i] = m[i - 1][i - 1].first * m[i][i].first * m[i][i].second;
        m[i - 1][i].first = m[i - 1][i - 1].first;
        m[i - 1][i].second = m[i][i].second;
    }

    for (int gap = 2; gap < n; gap++) {
        for (int i = 0; i < n - gap; i++) {
            for (int j = i; j < i + gap; j++) {
                if (cmm[i][i + gap] > cmm[i][j] + cmm[j + 1][i + gap] + m[i][j].first * m[i][j].second * m[j + 1][i + gap].second) {
                    cmm[i][i + gap] = cmm[i][j] + cmm[j + 1][i + gap] + m[i][j].first * m[i][j].second * m[j + 1][i + gap].second;
                    m[i][i + gap].first = m[i][j].first;
                    m[i][i + gap].second = m[j + 1][i + gap].second;
                }
            }
        }
    }

    cout << cmm[0][n - 1];

    return 0;
}