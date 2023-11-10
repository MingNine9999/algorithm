//Problem Number : 2456
//Problem Title : 나는 학급회장이다
//Problem Link : https://www.acmicpc.net/problem/2456

#include <iostream>

using namespace std;

int score[3][3];

int main() {
	int n;
	int three = 0, two = 0, one = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> one >> two >> three;
		score[0][0] += one;
		if (one == 3) {
			score[0][1]++;
		}
		else if (one == 2) {
			score[0][2]++;
		}
		score[1][0] += two;
		if (two == 3) {
			score[1][1]++;
		}
		else if (two == 2) {
			score[1][2]++;
		}
		score[2][0] += three;
		if (three == 3) {
			score[2][1]++;
		}
		else if (three == 2) {
			score[2][2]++;
		}
	}

	int big = 0;
	int check = 0;
	for (int i = 1; i < 3; i++) {
		if (score[big][0] < score[i][0]) {
			big = i;
		}
		else if (score[big][0] == score[i][0]) {
			if (score[big][1] < score[i][1]) {
				big = i;
			}
			else if (score[big][1] == score[i][1]) {
				if (score[big][2] < score[i][2]) {
					big = i;
				}
				else if (score[big][2] == score[i][2]) {
					check = i;
				}
			}
		}
	}
	if (check && big != 2) {
		cout << 0 << " " << score[big][0];
	}
	else {
		cout << big + 1 << " " << score[big][0];
	}

	return 0;
}