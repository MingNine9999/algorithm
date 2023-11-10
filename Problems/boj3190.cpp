//Problem Number : 3190
//Problem Title : 뱀
//Problem Link : https://www.acmicpc.net/problem/3190

#include <iostream>
#include <list>

using namespace std;

struct point {
	int h;
	int v;
};

int map[102][102];
int goY[4] = { 0,1,0,-1 };
int goX[4] = { 1,0,-1,0 };
pair<int, char> com[101];
list<point> snake;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		map[n + 1][i] = -1;
		map[i][n + 1] = -1;
		map[0][i] = -1;
		map[i][0] = -1;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int h, v;
		cin >> h >> v;
		map[h][v] = 1;
	}

	int l;
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> com[i].first >> com[i].second;
	}

	point head ,tail;
	head.h = 1;
	head.v = 1;
	tail = head;
	snake.push_back(head);
	int dir = 0;
	int c = 0;
	int t;
	map[1][1] = 1;
	for (t = 0; map[head.h][head.v] != -1; t++) {
		if (map[head.h][head.v] != 1) {
			map[tail.h][tail.v] = 0;
			snake.erase(snake.begin());
			tail = snake.front();
		}
		map[head.h][head.v] = -1;
		
		if (com[c].first == t) {
			if (com[c].second == 'D') {
				dir++;
				if (dir > 3) {
					dir = 0;
				}
			}
			else {
				dir--;
				if (dir < 0) {
					dir = 3;
				}
			}
			c++;
		}

		head.h += goY[dir];
		head.v += goX[dir];
		snake.push_back(head);
	}

	std::cout << t;

	return 0;
}