//Problem Number : 1138
//Problem Title : 한 줄로 서기
//Problem Link : https://www.acmicpc.net/problem/1138

#include <iostream>

using namespace std;

int man[11];
int line[11];
int check[11];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> man[i];
		check[i - 1] = 1;
	}

	int pos;
	for (int i = 1; i <= n; i++) {
		for (pos = 0; man[i] || check[pos] == 0; pos++) {
			man[i] -= check[pos];
		}
		line[pos] = i;
		check[pos] = 0;
	}

	for (int i = 0; i < n; i++) {
		cout << line[i] << " ";
	}

	return 0;
}