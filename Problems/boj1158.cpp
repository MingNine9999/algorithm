//Problem Number : 1158
//Problem Title : 요세푸스 문제
//Problem Link : https://www.acmicpc.net/problem/1158

#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int i = 0;
	cout << "<";
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		i++;
		if (i != m) {
			q.push(tmp);
		}
		else {
			cout << tmp;
			i = 0;
			if (q.empty()) {
				cout << ">";
			}
			else {
				cout << ", ";
			}
		}
	}

	return 0;
}