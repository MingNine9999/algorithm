//Problem Number : 2615
//Problem Title : 오목
//Problem Link : https://www.acmicpc.net/problem/2615

#include <iostream>

using namespace std;

int map[21][21];
int goX[4] = { 1,0,1,1};
int goY[4] = { 0,1,1,-1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int h = 1; h <= 19; h++) {
		for (int v = 1; v <= 19; v++) {
			cin >> map[h][v];
		}
	}
	int victory;
	for (int h = 1; h <= 19; h++) {
		for (int v = 1; v <= 19; v++) {
			victory = 0;
			if (map[h][v]) {
				victory = 1;
				for (int i = 0; i < 4; i++) {
					if (map[h][v] == map[h + goY[i]][v + goX[i]]) {
						victory = 2;
						for (int j = 2; j < 6; j++) {
							if (map[h][v] != map[h + j * goY[i]][v + j * goX[i]]) {
								break;
							}
							victory++;
						}
						if (victory == 5) {
							if (map[h][v] != map[h + -1 * goY[i]][v + -1 * goX[i]]) {
								cout << map[h][v] << endl;
								cout << h  << " " << v;
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout << 0;

	return 0;
}