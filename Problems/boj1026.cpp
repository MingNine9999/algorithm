//Problem Number : 1026
//Problem Title : 보물
//Problem Link : https://www.acmicpc.net/problem/1026

#include <iostream>
#include <algorithm>

using namespace std;

int a[51];
int b[51];

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n, greater<int>());
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}

	cout << ans << endl;

	return 0;
}