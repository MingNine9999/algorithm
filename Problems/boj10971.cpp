//Problem Number : 10971
//Problem Title : 외판원 순회 2
//Problem Link : https://www.acmicpc.net/problem/10971

#include <iostream>

#define MAXINT 2147483647

using namespace std;

int n;
int mat[12][12];
int minValue = MAXINT;
int first[12];

void dfs(const int level,int route[12], int value) {
	if (level == n - 1) {
		int extra[12] = { 0 }, i;
		for (i = 1; i <= n; i++){
			extra[route[i]] = 1;
		}
		for (i--; i > 0; i--) {
			if (extra[i] == 0) {
				break;
			}
		}
		if (mat[route[level]][i] == 0 || mat[i][1] == 0) {
			return;
		}
		value += mat[route[level]][i] + mat[i][1];
		
		if (value < minValue) {
			minValue = value;
		}
		return;
	}

	for (int i = 1; i <= n; i++) {
		int check = 0, plus;
		for (int j = 1; j <= level; j++) {
			if (route[j] == i) {
				check = 1;
			}
		}
		if (check) {
			continue;
		}

		route[level + 1] = i;
		plus = mat[route[level]][i];
		if (plus == 0) {
			continue;
		}
		if (value + plus < minValue) {
			dfs(level + 1, route, value + plus);
		}
	}

}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	first[1] = 1;

	dfs(1,first,0);

	cout << minValue;

	return 0;
}