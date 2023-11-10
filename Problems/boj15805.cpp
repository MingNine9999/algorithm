//Problem Number : 15805
//Problem Title : 트리 나라 관광 가이드
//Problem Link : https://www.acmicpc.net/problem/15805

#include <iostream>
#include <algorithm>

using namespace std;

bool visit[200001];
int ans[200001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a;
    int maxi = -1;
    int pre = -1;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        
        maxi = max(maxi, a);
        
        if (visit[a] == false) {
            visit[a] = true;
            ans[a] = pre;
        }
        pre = a;
    }
    
    cout << maxi + 1 << "\n";
    for (int i = 0; i <= maxi; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}