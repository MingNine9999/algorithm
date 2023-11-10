//Problem Number : 1074
//Problem Title : Z
//Problem Link : https://www.acmicpc.net/problem/1074

#include <iostream>

using namespace std;

int recur(int n2, int r, int c)
{
    int n = n2 >> 1;

    if (n == 0) {
        return 0;
    }

    if (c < n && r < n) {
        return recur(n, r, c);
    }
    else if (r < n) {
        return recur(n, r, c - n) + n * n;
    }
    else if (c < n) {
        return recur(n, r - n, c) + n * n * 2;
    }
    else {
        return recur(n, r - n, c - n) + n * n * 3;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r, c;

    cin >> n >> r >> c;

    cout << recur(2 << n, r, c);

    return 0;
}