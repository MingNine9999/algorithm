//Problem Number : 5612
//Problem Title : 터널의 입구와 출구
//Problem Link : https://www.acmicpc.net/problem/5612

#include <iostream>

using namespace std;
int in[10001];
int out[10001];

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	int max = m;

	for (int i = 0; i < n; i++) {
		cin >> in[i] >> out[i];
	}

	for (int i = 0; i < n; i++) {
		m = m + in[i] - out[i];
		if (m < 0) {
			cout << 0;
			return 0;
		}
		if (max < m) {
			max = m;
		}
	}
	cout << max;

	return 0;
}