//Problem Number : 17609
//Problem Title : 회문
//Problem Link : https://www.acmicpc.net/problem/17609

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char str[111111];

int isPal(int l, int r, int check)
{
    if (l >= r || check > 1) {
        return check;
    }

    if (str[l] == str[r]) {
        return isPal(l + 1, r - 1, check);
    }
    else {
        return min(isPal(l + 1, r, check + 1), isPal(l, r - 1, check + 1));
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;

        cout << isPal(0, strlen(str) - 1, 0) << '\n';
    }




    return 0;
}