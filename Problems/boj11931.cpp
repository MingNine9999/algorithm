//Problem Number : 11931
//Problem Title : 수 정렬하기 4
//Problem Link : https://www.acmicpc.net/problem/11931

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;

int main() {
	int n,a;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		num.push_back(a);
	}

	sort(num.begin(), num.end(), greater<int>());

	for (int i = 0; i < n; i++) {
		printf("%d\n", num[i]);
	}

	return 0;
}