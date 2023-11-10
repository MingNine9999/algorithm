//Problem Number : 5904
//Problem Title : Moo 게임
//Problem Link : https://www.acmicpc.net/problem/5904

#include <iostream>

using namespace std;

int dp[50];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	
	cin >> n;

	dp[0] = 3;
	for (int i = 1; dp[i - 1] <= n; i++) {
		dp[i] = 2 * dp[i - 1] + i + 3;
	}

	while (1) {
		int i;
		for (i = 0; dp[i] <= n; i++);
		i--;

		n -= dp[i];
		if (n <= i + 4) {
			break;
		}
		else {
			n -= i + 4;
		}
	}

	if (n == 1) {
		cout << "m";
	}
	else {
		cout << "o";
	}

	return 0;
}
