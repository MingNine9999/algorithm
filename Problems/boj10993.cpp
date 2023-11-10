//Problem Number : 10993
//Problem Title : º° Âï±â - 18
//Problem Link : https://www.acmicpc.net/problem/10993

#include <cstdio>
#include <algorithm>

#define MP make_pair
using namespace std;

char star[3333][4444];

struct ans {
	int y;
	int x;
	int h;
	int w;
};

ans rec(int n, int N, int y, int x, int h, int c)
{
	if (n > N) {
		return { -1,-1,-1,-1 };
	}
	
	ans ret;

	if (n % 2 == 0) {
		ret = rec(n + 1, N, y - h, x - h - 1, h * 2 + 1, c);
	}
	else {
		ret = rec(n + 1, N, y - 1, x - h - 1, h * 2 + 1, c);
	}

	if (ret.y == -1) {
		for (int i = y; i < y + h; i++) {
			for (int j = x; j < 2 * c - x + 1; j++) {
				star[i][j] = ' ';
			}
		}

		ret = { y, x, h, 2 * h - 1};
	}

	if (n % 2 == 0) {
		int yy, x1, x2;
		yy = y + h - 1;
		x1 = x2 = c;

		while (yy != y) {
			star[yy][x1] = star[yy][x2] = '*';
			yy--;
			x1--;
			x2++;
		}
		for (int i = x1; i <= x2; i++) {
			star[yy][i] = '*';
		}
	}
	else {
		int yy, x1, x2;
		yy = y;
		x1 = x2 = c;

		while (yy != y + h - 1) {
			star[yy][x1] = star[yy][x2] = '*';
			yy++;
			x1--;
			x2++;
		}
		for (int i = x1; i <= x2; i++) {
			star[yy][i] = '*';
		}
	}

	return ret;
}

int main(void)
{
	int n;
	int c;

	scanf("%d", &n);

	ans ret = rec(1, n, 1111, 2222, 1, 2222);
	int check = n % 2 ? 2222 + 1 : ret.x + ret.w;

	for (int i = ret.y; i < ret.y + ret.h; i++) {
		for (int j = ret.x; j < check; j++) {
			
			printf("%c", star[i][j]);
		}
		check += (n % 2 ? 1 : -1);
		printf("\n");
	}

	return 0;
}