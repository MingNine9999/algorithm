//Problem Number : 10275
//Problem Title : °ñµå ·¯½Ã
//Problem Link : https://www.acmicpc.net/problem/10275

#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		ll n, a, b;

		cin >> n >> a >> b;

		ll c = a & -a;
		int ans = 0;

		while (c > 0) {
			c >>= 1;
			ans--;
		}

		cout << n + ans + 1 << '\n';
	}

	return 0;
}