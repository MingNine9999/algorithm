//Problem Number : 10870
//Problem Title : 피보나치 수 5
//Problem Link : https://www.acmicpc.net/problem/10870

#include <iostream>

using namespace std;

int fibo(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main(void)
{
    int n;
    
    scanf("%d", &n);
    printf("%d", fibo(n));
    
    return 0;
}