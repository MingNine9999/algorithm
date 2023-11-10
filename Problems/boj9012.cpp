//Problem Number : 9012
//Problem Title : 괄호
//Problem Link : https://www.acmicpc.net/problem/9012

#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

stack<char> s;
char bracket[51];


int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		memset(bracket, 0, sizeof(char) * 51);
		while (s.empty() == 0) {
			s.pop();
		}

		cin >> bracket;
		for (int i = 0; bracket[i] != 0; i++) {
			if (bracket[i] == '(') {
				s.push('(');
			}
			else {
				if (s.empty()) {
					s.push('*');
					break;
				}
				else {
					s.pop();
				}
			}
		}
		if (s.empty()) {
			cout << "YES\n";
		}
		else {

			cout << "NO\n";
		}
	}

	return 0;
}