//Problem Number : 2877
//Problem Title : 4와 7
//Problem Link : https://www.acmicpc.net/problem/2877

#include <iostream>

using namespace std;

int num[33];
int bin[33];

int main() {
	int n;
	cin >> n;

	int k;
	n--;
	for (k = 1;1; k++) {
		num[k] = num[k - 1] * 2 + 2;
		if (num[k] > n) {
			break;
		}
	}

	n -= num[k - 1];

	for (int i = 0; n > 0; i++) {
		bin[i] = n % 2;
		n /= 2;
	}

	for (int i = k - 1; i >= 0; i--) {
		if (bin[i] == 0) {
			cout << 4;
		}
		else {
			cout << 7;
		}
	}

	return 0;
}