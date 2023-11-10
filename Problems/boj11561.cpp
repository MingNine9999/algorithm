//Problem Number : 11561
//Problem Title : Â¡°Ë´Ù¸® 
//Problem Link : https://www.acmicpc.net/problem/11561

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
		ll n;
		ll ans = 0;
		ll jmp = 1;

		cin >> n;

		int l = 1, r = 1e9;
		while (l < r) {
			ll mid = (l + r + 1) / 2;
			ll ta = (mid + 1) * mid / 2;

			if (ta <= n) {
				l = mid;
			}
			else {
				r = mid - 1;
			}
		}

		cout << l << '\n';
	}


	return 0;
}