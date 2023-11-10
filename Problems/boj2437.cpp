//Problem Number : 2437
//Problem Title : 저울
//Problem Link : https://www.acmicpc.net/problem/2437

#include <iostream>
#include <algorithm>

using namespace std;

int weight[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	sort(weight, weight + n);

	int ans = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (weight[i] > ans + 1) {
			cout << ans + 1;
			break;
		}
		
		ans += weight[i];
	}

	if (i == n) {
		cout << ans + 1;
	}

	return 0;

}