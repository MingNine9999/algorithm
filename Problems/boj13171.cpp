//Problem Number : 13171
//Problem Title : A
//Problem Link : https://www.acmicpc.net/problem/13171

#include <iostream>
#include <algorithm>

#define MOD (ll)(1e9 + 7)

using ll = long long;
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, x;
	ll ans = 1;

	cin >> a >> x;

	a %= MOD;

	while (x) {
		if (x & 1) {
			ans = (ans * a) % MOD;
		}

		a = (a * a) % MOD;
		x >>= 1;
	}

	cout << ans;

	return 0;
}