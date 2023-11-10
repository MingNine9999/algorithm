//Problem Number : 17436
//Problem Title : 소수의 배수
//Problem Link : https://www.acmicpc.net/problem/17436

#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

ll prime[11];
vector<ll> check[11];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> prime[i];
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll t = 0;

		ll c = 1;
		for (int j = i; j > 0; j--) {
			for (int k = 0; k < check[j - 1].size(); k++) {
				ll tmp = check[j - 1][k] * prime[i];
				t += (m / tmp) * c;
				check[j].push_back(tmp);
			}
			c *= -1;
		}
		check[0].push_back(prime[i]);

		t += (m / prime[i]) * c;

		ans += (t > 0 ? t : -t);
	}

	cout << ans;

	return 0;
}