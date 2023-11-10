//Problem Number : 3986
//Problem Title : 좋은 단어
//Problem Link : https://www.acmicpc.net/problem/3986

#include <iostream>
#include <stack>

using namespace std;

char word[1001][100001];

int main() {
	ios::sync_with_stdio(false);
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}
	
	int good = 0;

	for (int i = 0; i < n; i++) {
		stack<char> s;
		for (int j = 0; word[i][j] != NULL; j++) {
			if (s.empty()) {
				s.push(word[i][j]);
			}
			else {
				if (s.top() == word[i][j]) {
					s.pop(); 
				}
				else {
					s.push(word[i][j]);
				}
			}
		}

		if (s.empty()) {
			good++;
		}
	}

	cout << good;

	return 0;
}