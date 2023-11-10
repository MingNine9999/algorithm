//Problem Number : 2869
//Problem Title : 달팽이는 올라가고 싶다
//Problem Link : https://www.acmicpc.net/problem/2869

#include <cstdio>

int main(void)
{
    int a, b, v;
    int c, ans;
    
    scanf("%d%d%d", &a, &b, &v);
    
    v -= b;
    c = a - b;
    
    ans = v / c;
    if (v % c) {
        ans++;
    }
    
    printf("%d", ans);
    
    return 0;
}