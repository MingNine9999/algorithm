//Problem Number : 11504
//Problem Title : 돌려 돌려 돌림판!
//Problem Link : https://www.acmicpc.net/problem/11504

#include <iostream>
#include <algorithm>

using namespace std;

int X[11], Y[11];
int R[111];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int n, m;
		int mod = 1;
		int x = 0, y = 0;
		
		cin >> n >> m;

		for (int i = 0; i < m - 1; i++) {
			mod *= 10;
		}
		for (int i = 0; i < m; i++) {
			cin >> X[i];
			x *= 10;
			x += X[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> Y[i];
			y *= 10;
			y += Y[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> R[i];
		}

		int z = 0;
		for (int i = 0; i < m; i++) {
			z *= 10;
			z += R[i];
		}

		int ans = 0;
		for (int i = m; i < m + n; i++) {
			if (x <= z && z <= y) {
				ans++;
			}
			
			int idx = i % n;
			z %= mod;
			z *= 10;
			z += R[idx];
		}

		cout << ans << '\n';
	}

	return 0;
}