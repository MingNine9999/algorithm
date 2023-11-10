//Problem Number : 14174
//Problem Title : Block Game
//Problem Link : https://www.acmicpc.net/problem/14174

#include<stdio.h>
int cnt[256], c1[256], c2[256];
int max(int a, int b) { if (a > b)return a; return b; }
int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		char S1[12], S2[12];
		scanf("%s%s", S1, S2);
		for (j = 0; S1[j]; j++)c1[S1[j]]++;
		for (j = 0; S2[j]; j++)c2[S2[j]]++;
		for (j = 'a'; j <= 'z'; j++)cnt[j] += max(c1[j], c2[j]);
		for (j = 0; S1[j]; j++)c1[S1[j]]=0;
		for (j = 0; S2[j]; j++)c2[S2[j]]=0;
	}
	for (i = 'a'; i <= 'z'; i++)printf("%d\n", cnt[i]);
	return 0;
}