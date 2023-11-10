//Problem Number : 10808
//Problem Title : 알파벳 개수
//Problem Link : https://www.acmicpc.net/problem/10808

   #include <stdio.h>
   int main() {
       int n, i, k, a[26] = { 0 };
       char w[101] = { 0 };
       scanf("%s", &w);
       for (i = 97; i < 123; i++)
           for (k = 0; w[k] != 0; k++)
             if (w[k] == i)
                   a[i - 97]++;
     for (i = 0; i < 26; i++)
         printf("%d ", a[i]);
     return 0;
 }



