//Problem Number : 1919
//Problem Title : 애너그램 만들기
//Problem Link : https://www.acmicpc.net/problem/1919

#include <iostream>

using namespace std;

char alpha[2][26];
char input[2][1002];


int main() {
	cin >> input[0];
	cin >> input[1];
	
	for (int i = 0; input[0][i] != 0; i++) {
		alpha[0][input[0][i] - 'a']++;
	}
	for (int i = 0; input[1][i] != 0; i++) {
		alpha[1][input[1][i] - 'a']++;
	}

	int ans = 0;
	for (int i = 0; i < 26; i++) {
		int a = alpha[0][i] - alpha[1][i];
		if (a < 0) {
			a = -a;
		}
		ans += a;
	}

	cout << ans;

	return 0;
}