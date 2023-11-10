//Problem Number : 11505
//Problem Title : 구간 곱 구하기
//Problem Link : https://www.acmicpc.net/problem/11505

#include <iostream>

#define MOD 1000000007

using ll = long long;
using namespace std;

ll arr[2111111];
int siz = 0;

void init_seg(int n)
{
    siz = 1 << 20;
   
    for (int i = siz; i < siz * 2; i++) {
        arr[i] = 1;
    }
     for (int i = 0; i < n; i++) {
        cin >> arr[i + siz];
    }
    
    for (int i = siz - 1; i > 0 ; i--) {
        arr[i] = (arr[i * 2] * arr[i * 2 + 1]) % MOD;
    }
}

int update_seg(int pos, ll v)
{
    pos += siz - 1;
    arr[pos] = v;
    while (pos / 2) {
       pos /= 2;
       arr[pos] = (arr[pos * 2] * arr[pos * 2 + 1]) % MOD;
    }
    
    return pos;
}

ll cal_value(int s, int e, int l, int r, int pos)
{
    if (r < s || e < l) {
        return 1;
    }
    if (s <= l && r <= e) {
        return arr[pos];
    }
    
    return (cal_value(s, e, l, (l + r) / 2, pos * 2) * cal_value(s, e, (l + r) / 2 + 1, r, pos * 2 + 1)) % MOD;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    
    cin >> n >> m >> k;
    
    init_seg(n);
    
    int a, b, c;
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update_seg(b, (ll)c);
        }
        else {
            cout << cal_value(b, c, 1, siz, 1) << '\n';
        }
    }
    
    return 0;
}