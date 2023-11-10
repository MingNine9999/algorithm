//Problem Number : 1072
//Problem Title : 게임
//Problem Link : https://www.acmicpc.net/problem/1072

#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll x, y, z;
	
	cin >> x >> y;

	z = 100 * y / x;

	ll l = 1, r = 1e9 + 1;
	ll mid;

	while (l < r) {
		mid = (l + r) / 2;

		if (100 * (y + mid) / (x + mid) != z) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	
	if (r > 1e9) {
		cout << -1;
	}
	else {
		cout << r;
	}

	return 0;
}
