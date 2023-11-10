//Problem Number : 11286
//Problem Title : 절댓값 힙
//Problem Link : https://www.acmicpc.net/problem/11286

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		int c = a, d = b;
		if (a < 0) {
			c = -c;
		}
		if (b < 0) {
			d = -d;
		}
		if (c == d) {
			return a > b;
		}
		
		return c > d;
	}
};
priority_queue<int, vector<int>,  cmp> pq;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;
		if (n == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(n);
		}
	}

	return 0;
}