//Problem Number : 17390
//Problem Title : 이건 꼭 풀어야 해!
//Problem Link : https://www.acmicpc.net/problem/17390

#include <iostream>
#include <algorithm>

using namespace std;

int arr[300030];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int a, b;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);
    for (int i = 2; i <= n; i++) {
        arr[i] += arr[i - 1];
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        cout << arr[b] - arr[a - 1] << '\n';
    }

    return 0;
}