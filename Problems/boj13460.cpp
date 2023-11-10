//Problem Number : 13460
//Problem Title : 구슬 탈출 2
//Problem Link : https://www.acmicpc.net/problem/13460

#include <iostream>
#include <queue>

using namespace std;

typedef struct p{
	int x;
	int y;
} point;

int goX[4] = { 1, 0, -1, 0 };
int goY[4] = { 0, 1, 0, -1 };

char mat[12][12];
queue<point> red;
queue<point> blue;
char visit[12][12][12][12];

point go(point p, int dir) {
	while(mat[p.x + goX[dir]][p.y + goY[dir]] == '.') {
		p.x += goX[dir];
		p.y += goY[dir];
	}

	if(mat[p.x + goX[dir]][p.y + goY[dir]] == 'O') {
		p.x = p.y = -1;
	}

	return p;
}

int tilt() {
	int ret = 0;

	point RB = red.front();
	point BB = blue.front();
	visit[RB.x][RB.y][BB.x][BB.y] = 1;

	for(int i = 0; i < 4; i++) {
		point tmpR = go(RB, i);
		point tmpB = go(BB, i);

		if(tmpB.x == -1) {
			continue;
		}
		else if(tmpR.x == -1) {
			return -1;
		}

		if(visit[tmpR.x][tmpR.y][tmpB.x][tmpB.y] != 1) {
			if(tmpR.x == tmpB.x && tmpR.y == tmpB.y) {
				switch (i) {
					case 0 :
						RB.x > BB.x ? tmpB.x-- : tmpR.x--;
						break;

					case 1 :
						RB.y > BB.y ? tmpB.y-- : tmpR.y--;
						break;

					case 2 :
						RB.x > BB.x ? tmpR.x++ : tmpB.x++;
						break;

					case 3 :
						RB.y > BB.y ? tmpR.y++ : tmpB.y++;
						break;
				}
			}
			red.push(tmpR);
			blue.push(tmpB);
			ret++;
		}
	}

	red.pop();
	blue.pop();

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;


	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if(mat[i][j] == 'R') {
				point r;
				r.x = i;
				r.y = j;
				red.push(r);
				mat[i][j] = '.';
			}
			else if(mat[i][j] == 'B') {
				point b;
				b.x = i;
				b.y = j;
				blue.push(b);
				mat[i][j] = '.';
			}
		}
	}

	int ans = 0;
	int check = 1;

	while(ans <= 10) {
		ans++;
		int c = 0;
		for(int i = 0; i < check; i++) {
			int t = tilt();
			if(t == -1) {
				c = t;
				break;
			}
			c += t;
		}
		if(c == -1) {
			break;
		}
		check = c;
	}

	if(ans > 10) {
		ans = -1;
	}

	cout << ans;

	return 0;
}
