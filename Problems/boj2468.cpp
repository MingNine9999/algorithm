//Problem Number : 2468
//Problem Title : 안전 영역
//Problem Link : https://www.acmicpc.net/problem/2468

#include<cstdio>
#include <algorithm>

using namespace std;
int arr[105][105];
int check[105][105];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void dfs(int x, int y){
    check[x][y]=0;
    for(int i=0;i<4;i++){
        if(check[x+dx[i]][y+dy[i]]==1){
            dfs(x+dx[i], y+dy[i]);
        }
    }
    return;
}
int main(){
    int n;
    int height;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d", &x);
            height=max(x,height);
            arr[i][j]=x;
        }
    }
    int ans=1;
    for(int i=1;i<=100;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            for(int q=1;q<=n;q++){
                if(arr[j][q]<i){
                    check[j][q]=0;
                }
                else{
                    check[j][q]=1;
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int q=1;q<=n;q++){
                if(check[j][q]==1){
                    cnt+=1;
                    dfs(j,q);
                }
            }
        }
        ans=max(cnt,ans);
    }
    printf("%d", ans);

    return 0;
}