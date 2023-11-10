//Problem Number : 11650
//Problem Title : 좌표 정렬하기
//Problem Link : https://www.acmicpc.net/problem/11650

#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> dot[100001];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &dot[i].first, &dot[i].second);
	}

	sort(dot, dot + n);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", dot[i].first, dot[i].second);
	}

	return 0;
}