//Problem Number : 16953
//Problem Title : A → B
//Problem Link : https://www.acmicpc.net/problem/16953

#include <iostream>
#include <queue>

using ll = long long;
using namespace std;

queue<ll> q;
queue<ll> tq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    int lv = 0;
    int check = 1;

    cin >> a >> b;

    q.push(a);

    while (!q.empty() && check) {
        while (!q.empty()) {
            ll f = q.front(); q.pop();

            //cout << f << endl;
            if (f == b) {
                check = 0;
            }

            if (f * 2 <= b) {
                tq.push(f * 2);
            }
            if (f * 10 + 1 <= b) {
                tq.push(f * 10 + 1);
            }
        }

        while (!tq.empty()) {
            q.push(tq.front()); tq.pop();
        }
        lv++;
    }

    if (check == 0) {
        cout << lv;
    }
    else {
        cout << -1;
    }

    return 0;
}