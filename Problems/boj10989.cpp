//Problem Number : 10989
//Problem Title : 수 정렬하기 3
//Problem Link : https://www.acmicpc.net/problem/10989

#include <iostream>

using namespace std;

int num[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        num[a]++;
    }
    
    for(int i = 1; i <= 10000; i++) {
        while(num[i]--){
            cout << i << "\n";
        }
    }
    
    return 0;
}