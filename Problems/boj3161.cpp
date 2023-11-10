//Problem Number : 3161
//Problem Title : izbori
//Problem Link : https://www.acmicpc.net/problem/3161

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int m, n;
int arr[55][55];
int man[55];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int b = 1;
        for (int j = 1; j <= n; j++) {
            cin >> a;
            arr[i][a] = b++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int check = 0;
            for (int k = 0; k < m; k++) {
                if (arr[k][i] < arr[k][j]) {
                    check--;
                }
                else {
                    check++;
                }
            }
            check < 0 ? man[i]++ : man[j]++;
        }
    }

    int MAX = 0;

    for (int i = 1; i <= n; i++) {
        MAX = max(MAX, man[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (man[i] == MAX) {
            cout << i << '\n';
        }
    }

    return 0;
}