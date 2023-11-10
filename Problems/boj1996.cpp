//Problem Number : 1996
//Problem Title : 지뢰 찾기
//Problem Link : https://www.acmicpc.net/problem/1996

#include <iostream>

using namespace std;

char input[1004][1004];
char output[1004][1004];

int searchY[8] = { -1,-1,-1,0,0,1,1,1 };
int searchX[8] = { -1,0,1,-1,1,-1,0,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int h = 1; h <= n; h++) {
		for (int v = 1; v <= n; v++) {
			cin >> input[h][v];
		}
	}


	for (int h = 1; h <= n; h++) {
		for (int v = 1; v <= n; v++) {
			if (input[h][v] == '.') {
				int bomb = 0;
				for (int i = 0; i < 8; i++) {
					if (input[h + searchY[i]][v + searchX[i]] != '.' && input[h + searchY[i]][v + searchX[i]] != 0) {
						bomb += input[h + searchY[i]][v + searchX[i]] - '0';
					}
				}
				if (bomb > 9) {
					output[h][v] = 'M';
				}
				else {
					output[h][v] = bomb + '0';
				}
			}
			else {
				output[h][v] = '*';
			}
			cout << output[h][v];
		}
		cout << "\n";
	}




	return 0;
}