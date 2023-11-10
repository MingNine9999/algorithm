//Problem Number : 6161
//Problem Title : iCow
//Problem Link : https://www.acmicpc.net/problem/6161

#include <iostream>

using namespace std;

int rate[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> rate[i];
	}

	while (t--) {
		int maxi = 0, val;
		for (int i = 1; i < n; i++) {
			if (rate[maxi] < rate[i]) {
				maxi = i;
			}
		}

		val = rate[maxi];
		rate[maxi] = 0;

		for (int i = 0; i < n; i++) {
			if (i == maxi) {
				continue;
			}
			rate[i] += val / (n - 1);

			if (i < val % (n - 1) || (i > maxi && i == val % (n - 1))) {
				rate[i]++;
			}
		}

		cout << maxi + 1 << "\n";
	}

	return 0;
}