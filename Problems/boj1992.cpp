//Problem Number : 1992
//Problem Title : 쿼드트리
//Problem Link : https://www.acmicpc.net/problem/1992

#include <iostream>

using namespace std;

char map[66][66];

void quadtree(int startY, int startX, int range) {
	for (int y = startY; y <= startY + range - 1; y++) {
		for (int x = startX; x <= startX + range - 1; x++) {
			if (map[startY][startX] != map[y][x]) {
				cout << "(";
				quadtree(startY, startX, range / 2);
				quadtree(startY, startX + range / 2, range / 2);
				quadtree(startY + range / 2, startX, range / 2);
				quadtree(startY + range / 2, startX + range / 2, range / 2);
				cout << ")";

				return;
			}
		}
	}

	cout << map[startY][startX];

	return;
}


int main() {
	int n;

	cin >> n;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> map[y][x];
		}
	}

	quadtree(1, 1, n);

	return 0;
}
