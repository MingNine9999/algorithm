//Problem Number : 1213
//Problem Title : 팰린드롬 만들기
//Problem Link : https://www.acmicpc.net/problem/1213

#include <iostream>

using namespace std;

int alpha[27];
char input[51];
char output[51];

int main() {
	cin >> input;

	for (int i = 0; input[i] != 0; i++) {
		alpha[input[i] - 'A']++;
	}

	int cen = -1;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) {
			if (cen == -1) {
				cen = i;
				alpha[i]--;
			}
			else {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}

	int check = 0;
	for (int i = 0; i < 26; i++) {
		int mid = alpha[i] / 2;
		while (alpha[i] > mid) {
			output[check] = i + 'A';
			check++;
			alpha[i]--;
		}
	}
	if (cen != -1) {
		output[check++] = cen + 'A';
	}

	for (int i = 25; i >= 0; i--) {
		while (alpha[i]) {
			output[check] = i + 'A';
			check++;
			alpha[i]--;
		}
	}

	cout << output;

	return 0;
}