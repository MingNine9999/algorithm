//Problem Number : 2751
//Problem Title : 수 정렬하기 2
//Problem Link : https://www.acmicpc.net/problem/2751

#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int arr[1111111];

int main(void)
{
    int n;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
       scanf("%d", &arr[i]); 
    }
    
    sort(arr, arr + n);
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}