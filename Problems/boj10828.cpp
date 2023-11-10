//Problem Number : 10828
//Problem Title : 스택
//Problem Link : https://www.acmicpc.net/problem/10828

#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> s;

int main() {
	int n;
	cin >> n;

	string com;
	int a;

	for (int i = 0; i < n; i++) {
		a = -1;
		cin >> com;

		if (com == "push") {
			cin >> a;
			s.push(a);
		}
		else if (com == "pop") {
			if (s.empty()) {
				cout << a << endl;
			}
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (com == "size") {
			cout << s.size() << endl;
		}
		else if (com == "empty") {
			cout << s.empty() << endl;
		}
		else if (com == "top") {
			if (s.empty()) {
				cout << a << endl;
			}
			else {
				cout << s.top() << endl;
			}
		}
		
	}


	return 0;
}