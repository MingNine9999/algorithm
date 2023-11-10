//Problem Number : 14175
//Problem Title : The Cow-Signal
//Problem Link : https://www.acmicpc.net/problem/14175

#include<stdio.h>
char X[15][15];
int main() {
	int n, m, k;
	int i, j, p, q;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < n; i++)scanf("%s", X[i]);
	for (i = 0; i < n; i++)for (p = 0; p < k; p++) {
		for (j = 0; j < m; j++)for (q = 0; q < k; q++) {
			printf("%c", X[i][j]);
		}
		puts("");
	}
	return 0;
}