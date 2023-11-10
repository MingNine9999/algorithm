//Problem Number : 1874
//Problem Title : 스택 수열
//Problem Link : https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int number[100001];
char cal[100001];

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	int next = 1, c = 0;
	int pop = 0, i = 0;

	while (pop < n) {
		if (s.empty() || s.top() < number[i]) {
			s.push(next++);
			cal[c++] = '+';
		}
		else if (s.top() == number[i]) {
			s.pop();
			cal[c++] = '-';
			pop++;
			i++;
		}
		else {
			break;
		}
	}

	if (pop != n) {
		cout << "NO";
	}
	else {
		for (int j = 0; j < n * 2; j++) {
			cout << cal[j] << "\n";
		}
	}

	return 0;
}