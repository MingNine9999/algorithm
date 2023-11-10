//Problem Number : 11651
//Problem Title : 좌표 정렬하기 2
//Problem Link : https://www.acmicpc.net/problem/11651

#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> dot[100001];

bool compare(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &dot[i].first, &dot[i].second);
	}

	sort(dot, dot + n, compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", dot[i].first, dot[i].second);
	}


	return 0;
}