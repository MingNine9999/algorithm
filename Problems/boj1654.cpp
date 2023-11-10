//Problem Number : 1654
//Problem Title : 랜선 자르기
//Problem Link : https://www.acmicpc.net/problem/1654

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector<int> v;

int par(long long l, long long r)
{
    if (l >= r) {
        return l;
    }
    long long mid = (l + r + 1) / 2;
    int num = 0;

    for (int i = 0; i < k; i++) {
        num += v[i] / mid;
    }

    if (num >= n) {
        return par(mid, r);
    }
    else {
        return par(l, mid - 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int maxi = -1;

    cin >> k >> n;

    v.resize(k + 1);
    for (int i = 0; i < k; i++) {
        cin >> v[i];

        maxi = max(maxi, v[i]);
    }

    cout << par(1, (long long)maxi);

    return 0;
}