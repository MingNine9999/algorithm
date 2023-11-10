//Problem Number : 10810
//Problem Title : 공 넣기
//Problem Link : https://www.acmicpc.net/problem/10810

 #include <stdio.h>
   int main(){
       int n,m,i,j,k,l,p,b[100]={0};
       scanf("%d %d",&n,&m);
       for(l=0;l<m;l++){
           scanf("%d %d %d",&i,&j,&k);
           for(p=i;p<=j;p++)
               b[p-1]=k;
       }
      for(l=0;l<n;l++)
          printf("%d ",b[l]);
      return 0;
  }
