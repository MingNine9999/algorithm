//Problem Number : 1935
//Problem Title : 후위 표기식2
//Problem Link : https://www.acmicpc.net/problem/1935

#include <iostream>
#include <stack>

using namespace std;

stack<double> s;
char modify[111];
int num[30];

int main() {
	int n;
	cin >> n;
	cin >> modify;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	double a, b;
	for (int i = 0; modify[i] != NULL; i++) {
		if (modify[i] >= 'A' && modify[i] <= 'Z') {
			s.push(num[modify[i] - 'A']);
		}
		else {
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			if (modify[i] == '+') {
				s.push(b + a);
			}
			else if (modify[i] == '-') {
				s.push(b - a);
			}
			else if (modify[i] == '*') {
				s.push(b * a);
			}
			else if (modify[i] == '/') {
				s.push(b / a);
			}
		}
	}

	printf("%.2lf", s.top());

	return 0;
}