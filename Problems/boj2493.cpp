//Problem Number : 2493
//Problem Title : 탑
//Problem Link : https://www.acmicpc.net/problem/2493

#include <iostream>
#include <stack>

using namespace std;

int tower[500001];
stack <int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	s.push(0);
	tower[0] = 1234567890;

	for (int i = 1; i <= n; i++) {
		cin >> tower[i];

		while (tower[s.top()] < tower[i]) {
			s.pop();
		}

		cout << s.top() << " ";
		s.push(i);
	}

	return 0;
}