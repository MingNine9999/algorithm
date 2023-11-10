//Problem Number : 10811
//Problem Title : 바구니 뒤집기
//Problem Link : https://www.acmicpc.net/problem/10811

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector <int> v;
	int i;
	for (i = 1; i <= n;i++)
		v.push_back(i);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		reverse(v.begin() + a - 1, v.begin() + b);
	}
	for (i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	return 0;
}