//Problem Number : 2294
//Problem Title : 동전 2
//Problem Link : https://www.acmicpc.net/problem/2294

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int dp[10001];
set<int> coin;

int main() {
	int n, k;
	cin >> n >> k;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		coin.insert(input);
	}
	coin.insert(1234567890);

	auto iter = coin.begin();

	for (int i = 1; i <= k; i++) {
		for (iter = coin.begin(); *iter <= i; iter++) {
			if (*iter == i) {
				dp[i] = 1;
			}
			else {
				if (dp[i - *iter]) {
					if (dp[i] == 0) {
						dp[i] = dp[i - *iter] + 1;
					}
					else if (dp[i] > dp[i - *iter] + 1) {
						dp[i] = dp[i - *iter] + 1;
					}
				}
			}
		}

	}

	if (dp[k]) {
		cout << dp[k];
	}
	else {
		cout << -1;
	}

	return 0;
}