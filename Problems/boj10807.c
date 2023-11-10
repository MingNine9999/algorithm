//Problem Number : 10807
//Problem Title : 개수 세기
//Problem Link : https://www.acmicpc.net/problem/10807

#include <stdio.h>
int main (){
    int n,i,j,c=0,k[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&k[i]);
    scanf("%d",&j);
    for(i=0;i<n;i++)
        if(j==k[i]){
        c++;
    }
    printf("%d",c);
    return 0;
}
    