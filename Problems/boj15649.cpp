//Problem Number : 15649
//Problem Title : N과 M (1)
//Problem Link : https://www.acmicpc.net/problem/15649

#include <iostream>

using namespace std;

int N;
int out[11];
int visit[11];

void per(int n, int m)
{
    if (n == m) {
        for (int i = 0; i < m; i++) {
            cout << out[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visit[i] == 1) continue;

        out[n] = i;
        visit[i] = 1;
        per(n + 1, m);
        visit[i] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;

    cin >> N >> m;

    per(0, m);

    return 0;
}