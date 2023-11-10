//Problem Number : 10798
//Problem Title : 세로읽기
//Problem Link : https://www.acmicpc.net/problem/10798

#include <iostream>

using namespace std;

char w[5][16];

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> w[i];
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 5; j++) {
			if (w[j][i] == 0) {
				continue;
			}
			cout << w[j][i];
		}
	}
	   
	return 0;
}