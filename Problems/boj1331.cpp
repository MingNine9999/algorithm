//Problem Number : 1331
//Problem Title : 나이트 투어
//Problem Link : https://www.acmicpc.net/problem/1331

#include <iostream>
#include <vector>

#define A 'A'
#define N 36
#define MP make_pair
#define ABS(a) ((a) > 0 ? (a) : -(a))

using namespace std;

int check[11][11];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char a;
    int b;
    vector<pair<int, int> > v;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(MP((int) a - A + 1, b));
        if (0 > v[i].first || v[i].first > 6 || 0 > v[i].second || v[i].second > 6) {
            ans = -1;
        }
    }
    
    v.push_back(v[0]);
    for (int i = 1; i <= N && ans == 0; i++) {
        int f = ABS(v[i - 1].first - v[i].first);
        int s = ABS(v[i - 1].second - v[i].second);

        if (check[v[i].first][v[i].second] == 0 && f + s == 3 && ABS(f - s) == 1) {
            check[v[i].first][v[i].second] = 1;
        }
        else {
            ans = -1;
        }
    }

    cout << (ans ? "Invalid" : "Valid");

    return 0;
}