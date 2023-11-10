//Problem Number : 2217
//Problem Title : 로프
//Problem Link : https://www.acmicpc.net/problem/2217

#include <iostream>
#include <algorithm>

using namespace std;

int rope[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}

	sort(rope, rope + n);

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (rope[i] * (n - i) > max) {
			max = rope[i] * (n - i);
		}
	}

	cout << max;

	return 0;
}