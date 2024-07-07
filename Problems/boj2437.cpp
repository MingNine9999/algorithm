//Problem Number : 2437
//Problem Title : 저울
//Problem Link : https://www.acmicpc.net/problem/2437

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;

using namespace std;

vector<LL> in;
vector<vector<LL>> out;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    in.resize(n);
    out.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    sort(in.begin(), in.end());

    int max = 0;

    for (int i = 0; i < n; i++) {
        if (max + 1 < in[i]) {
            break;
        }

        max += in[i];
    }

    cout << max + 1;

    return 0;
}
