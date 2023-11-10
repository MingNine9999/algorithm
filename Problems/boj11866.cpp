//Problem Number : 11866
//Problem Title : 요세푸스 문제 0
//Problem Link : https://www.acmicpc.net/problem/11866

#include <iostream>
#include <queue>

using namespace std;

int list[1010];
queue<int> ans;

int main() {
	int n, m;

	cin >> n >> m;

	int check = 0;
	int r = 0;

	while (r != n) {
		for (int i = 0; i < m; i++) {
			check++;
			if (check > n) {
				check = 1;
			}
			if (list[check] == 1) {
				i--;
			}
		}
		list[check] = 1;
		ans.push(check);
		r++;
	}

	cout << "<";
	for (int i = 0; i < n; i++) {
		cout << ans.front();
		ans.pop();
		if (i != n - 1) {
			cout << ", ";
		}
	}
	cout << ">";

	return 0;
}