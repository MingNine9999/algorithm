//Problem Number : 1813
//Problem Title : 마지막 한마디
//Problem Link : https://www.acmicpc.net/problem/1813

#include <iostream>
#include <vector>

using namespace std;

int v[111111];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        v[a]++;
    }

    for (int i = n; i >= 0; i--) {
        
        if (v[i] == i) {
            cout << i;
            break;
        }
        if (i == 0) {
            cout << -1;
        }
    }

    return 0;
}