//Problem Number : 12789
//Problem Title : 도키도키 간식드리미
//Problem Link : https://www.acmicpc.net/problem/12789

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int> s;
queue<int> q;

int main() {
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		q.push(k);
	}
	
	int i;

	for (i = 1; i < n; i++) {
		if (s.empty() == 0 && s.top() == i) {
			s.pop();
		}
		else if (q.empty() == 0 && q.front() == i) {
			q.pop();
		}
		else if (s.empty() == 0 && q.empty() == 0 && s.top() < q.front()) {
			break;
		}
		else {
			s.push(q.front());
			q.pop();
			i--;
		}
	}


	if (i == n) {
		cout << "Nice";
	}
	else {
		cout << "Sad";
	}
	

	return 0;
}