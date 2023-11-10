//Problem Number : 10610
//Problem Title : 30
//Problem Link : https://www.acmicpc.net/problem/10610

#include <iostream>

using namespace std;

char input[100001];
int num[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> input;
	bool check = false;

	for (int i = 0; input[i] != NULL; i++) {
		num[input[i] - '0']++;
	}

	if (num[0]) {
		int add = 0;
		for (int i = 1; i < 10; i++) {
			add += i * num[i];
		}

		if (add % 3 == 0) {
			for (int i = 9; i >= 0; i--) {
				while (num[i]--) {
					cout << i;
				}
			}
		}
		else {
			cout << -1;
		}
	}
	else {
		cout << -1;
	}

	return 0;
}