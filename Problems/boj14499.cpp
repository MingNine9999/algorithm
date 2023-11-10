//Problem Number : 14499
//Problem Title : 주사위 굴리기
//Problem Link : https://www.acmicpc.net/problem/14499

#include <iostream>
#include <algorithm>

using namespace std;

//             위뒤오왼앞아
int dice[] = { 0,0,0,0,0,0 };

int n, m;
int x, y;
int MAP[22][22];

const int goX[] = { 0,1,-1,0,0 };
const int goY[] = { 0,0,0,-1,1 };

void swap(int a, int b, int c, int d)
{
	int t = dice[a];
	dice[a] = dice[b];
	dice[b] = dice[c];
	dice[c] = dice[d];
	dice[d] = t;
}

void move(int com)
{
	int yy = y + goY[com];
	int xx = x + goX[com];

	if (yy < 0 || yy >= n || xx < 0 || xx >= m) {
		return;
	}

	y = yy;
	x = xx;

	switch (com) {
		case 1:
			swap(0, 2, 5, 3);
			break;
		case 2:
			swap(0, 3, 5, 2);
			break;
		case 3:
			swap(0, 1, 5, 4);
			break;
		case 4:
			swap(0, 4, 5, 1);
			break;
	}

	if (MAP[y][x] == 0) {
		MAP[y][x] = dice[5];
	}
	else {
		dice[5] = MAP[y][x];
		MAP[y][x] = 0;
	}

	cout << dice[0] << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c;
	int com;
	
	cin >> n >> m >> y >> x >> c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < c; i++) {
		cin >> com;
		move(com);
	}

	return 0;
}