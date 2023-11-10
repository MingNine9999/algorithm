//Problem Number : 1244
//Problem Title : 스위치 켜고 끄기
//Problem Link : https://www.acmicpc.net/problem/1244

#include <stdio.h>

int num[110];

int main() {
	int n, com;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	scanf("%d", &com);
	for (int i = 0; i < com; i++) {
		int s, k;
		scanf("%d%d", &s, &k);
		if (s == 1) {
			for (int j = 1; j <= n; j++) {
				if (j%k == 0) {
					if (num[j]) {
						num[j] = 0;
					}
					else {
						num[j] = 1;
					}
				}
			}
		}
		else if (s == 2) {
			if (k == 1 || k == n) {
				if (num[k]) {
					num[k] = 0;
				}
				else {
					num[k] = 1;
				}
			}
			else {
				int l = 0;
				while (k + l <= n && k - l >= 1 && num[k + l] == num[k - l]) {
					if (num[k + l]) {
						num[k + l] = 0, num[k - l] = 0;
					}
					else {
						num[k + l] = 1, num[k - l] = 1;
					}
					l++;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i > 2 && i % 20 == 1) {
			printf("\n");
		}
		printf("%d ", num[i]);
	}
	return 0;
}