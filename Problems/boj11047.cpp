//Problem Number : 11047
//Problem Title : 동전 0
//Problem Link : https://www.acmicpc.net/problem/11047

#include <iostream>

using namespace std;

int coin[11];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (coin[i] <= k) {
			ans += k / coin[i];
			k %= coin[i];
		}
	} 
	
	cout << ans;

	return 0;
}