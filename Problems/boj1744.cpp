//Problem Number : 1744
//Problem Title : 수 묶기
//Problem Link : https://www.acmicpc.net/problem/1744

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;

using namespace std;

vector<LL> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int zeroCount = 0;
    int minusCheck = 0;
    cin >> n;

    v.resize(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];

        if (v[i] == 0) {
            zeroCount++;
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size() - 1; i += 2) {
        if (v[i + 1] >= 0) {
            if (v[i] < 0 && zeroCount > 0) {
                v[i] = 0;
            }

            break;
        }

        v[i] = v[i] * v[i + 1];
        v[i + 1] = 0;

        minusCheck = i;
    }

    for (int i = v.size() - 1; i > 0; i -= 2) {
        if (v[i - 1] <= 1 || v[i] <= 1) {
            break;
        }

        v[i] = v[i] * v[i - 1];
        v[i - 1] = 0;
    }

    LL out = 0;
    for (int i = 0; i < n; i++) {
        out += v[i];
    }

    cout << out << '\n';

    return 0;
}
