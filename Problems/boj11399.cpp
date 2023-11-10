//Problem Number : 11399
//Problem Title : ATM
//Problem Link : https://www.acmicpc.net/problem/11399

#include <iostream>
#include <algorithm>

using namespace std;

int time[1001];
int ans[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}

	sort(time, time + n);

	ans[0] = time[0];
	ans[n] += ans[0];
	for (int i = 1; i < n; i++) {
		ans[i] = ans[i - 1] + time[i];
		ans[n] += ans[i];
	}

	cout << ans[n];

	return 0;
}