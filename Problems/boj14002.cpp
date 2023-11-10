//Problem Number : 14002
//Problem Title : 가장 긴 증가하는 부분 수열 4
//Problem Link : https://www.acmicpc.net/problem/14002

#include <iostream>
#include <algorithm>
#include <stack>

#define INF 1234567890
using namespace std;

int seq[1001];
int dp[1001];
int save[1001];
stack<int> s;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int low, longest = -1;
	int maxNum = -1;

	cin >> n;
	dp[0] = -INF;
	for (int i = 0; i < n; i++) {
		dp[i] = INF;
	}

	for (int i = 0; i < n; i++) {
		cin >> seq[i];

		low = lower_bound(dp, dp + n, seq[i]) - dp;

		dp[low] = seq[i];
		save[i] = low;

		if (longest < low) {
			longest = low;
			maxNum++;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (save[i] == maxNum) {
			s.push(seq[i]);
			maxNum--;
		}
	}

	cout << longest + 1 << "\n";
	while (s.empty() == 0) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}