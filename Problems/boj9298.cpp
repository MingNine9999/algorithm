//Problem Number : 9298
//Problem Title : Ant Entrapment
//Problem Link : https://www.acmicpc.net/problem/9298

#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int TC;
	scanf("%d", &TC);

	for (int tc = 1; tc <= TC; tc++) {
		double minX, minY, maxX, maxY;
		minX = minY = 1111.1;
		maxX = maxY = -1111.1;

		int n;
		double x, y;

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &x, &y);
			minX = min(minX, x);
			minY = min(minY, y);
			maxX = max(maxX, x);
			maxY = max(maxY, y);
		}

		x = maxX - minX;
		y = maxY - minY;

		printf("Case %d: Area %.9lf, Perimeter %.9lf\n", tc, x * y, (x + y) * 2);
	}

	return 0;
}