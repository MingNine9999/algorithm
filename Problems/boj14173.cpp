//Problem Number : 14173
//Problem Title : Square Pasture
//Problem Link : https://www.acmicpc.net/problem/14173

#include<stdio.h>
int max(int a, int b) { if (a == -1)return b; if (a < b)return b; return a; }
int min(int a, int b) { if (a == -1)return b; if (a < b)return a; return b; }
int main() {
	int mnx, mxx, mny, mxy;
	mnx = mxx = mny = mxy = -1;
	for (int i = 0; i < 4; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		mnx = min(mnx, x); mxx = max(mxx, x);
		mny = min(mny, y); mxy = max(mxy, y);
	}
	int c = max(mxx - mnx, mxy - mny);
	printf("%d", c*c);
	return 0;
}