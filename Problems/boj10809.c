//Problem Number : 10809
//Problem Title : 알파벳 찾기
//Problem Link : https://www.acmicpc.net/problem/10809

 #include <stdio.h>
   int main() {
       int n, i, k, a[26] = { 0 };
       char w[101] = { 0 };
       scanf("%s", &w);
       for(i=0;i<26;i++)
           a[i]=-1;
       for (i = 97; i < 123; i++)
           for (k = 0; w[k] != 0; k++)
              if (w[k] == i&&a[i-97]==-1)
                  a[i - 97]=k;
      for (i = 0; i < 26; i++)
          printf("%d ", a[i]);
     return 0;
  }
