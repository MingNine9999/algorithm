//Problem Number : 2830
//Problem Title : 행성 X3
//Problem Link : https://www.acmicpc.net/problem/2830

#include <iostream>

using namespace std;

int man[1000001];
int bin[25];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> man[i];
		if (man[i] > max) {
			max = man[i];
		}
	}
	unsigned long long ans = 0;

	for (int i = 0; max > 0; i++) {
		for (int j = 0; j < n; j++) {
			if ((man[j] & 1) == 1) {
				bin[i]++;
			}
			man[j] = man[j] >> 1;
		}
		max = max >> 1;
	}
	int pos = 1;
	for (int i = 0; i < 21; i++) {
		ans += (unsigned long long) pos * bin[i] * (n - bin[i]);
		pos *= 2;
	}
	cout << ans;

	return 0;
}