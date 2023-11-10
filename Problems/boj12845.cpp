//Problem Number : 12845
//Problem Title : 모두의 마블
//Problem Link : https://www.acmicpc.net/problem/12845

#include <iostream>
#include <algorithm>


using namespace std;

int level[1001];


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> level[i];
	}

	sort(level, level + n);

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += level[i] + level[n - 1];
	}

	cout << ans;

	return 0;
}