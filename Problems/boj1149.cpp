//Problem Number : 1149
//Problem Title : RGB거리
//Problem Link : https://www.acmicpc.net/problem/1149

#include <iostream>

using namespace std;

int value[1001][3];
int house[1001][3];

int main() {

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}

	value[0][0] = house[0][0];
	value[0][1] = house[0][1];
	value[0][2] = house[0][2];

	for (int i = 1; i < n; i++) {
		value[i][0] = min(value[i - 1][1], value[i - 1][2]) + house[i][0];
		value[i][1] = min(value[i - 1][0], value[i - 1][2]) + house[i][1];
		value[i][2] = min(value[i - 1][0], value[i - 1][1]) + house[i][2];
	}

	int ans = min(value[n - 1][0], value[n - 1][1]);
	ans = min(value[n - 1][2], ans);

	cout << ans;

	return 0;
}