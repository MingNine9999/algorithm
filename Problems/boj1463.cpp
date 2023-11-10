//Problem Number : 1463
//Problem Title : 1로 만들기
//Problem Link : https://www.acmicpc.net/problem/1463

#include <iostream>

using namespace std;

int times[1000001];

int min3(int a, int b, int c) {
	int d = a > b ? b : a;
	return c > d ? d : c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int input;
	int a, b, c;

	cin >> input;

	times[2] = 1;
	times[3] = 1;

	for (int i = 4; i <= input; i++) {
		a = b = c = 1234567890;
		if (i % 3 == 0) {
			a = times[i / 3];
		}

		if (i % 2 == 0) {
			b = times[i / 2];
		}

		c = times[i - 1];

		times[i] = min3(a, b, c) + 1;
	}

	cout << times[input];

	return 0;
}