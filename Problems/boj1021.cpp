//Problem Number : 1021
//Problem Title : 회전하는 큐
//Problem Link : https://www.acmicpc.net/problem/1021

#include <iostream>
#include <queue>

using namespace std;

deque<int> dq1;
deque<int> dq2;
int arr[55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		dq1.push_back(i);
		dq2.push_back(i);
	}
	for(int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	for(int i = 0; i < m; i++) {
		int calL = 0, calR = 0;
		while(dq1.front() != arr[i]) {
			int tmp = dq1.front();
			dq1.pop_front();
			dq1.push_back(tmp);
			calL++;
		}
		dq1.pop_front();
		while(dq2.front() != arr[i]) {
			int tmp = dq2.back();
			dq2.pop_back();
			dq2.push_front(tmp);
			calR++;
		}
		dq2.pop_front();

		ans += calL < calR ? calL : calR;
	}

	cout << ans;

	return 0;
}
