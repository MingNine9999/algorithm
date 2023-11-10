//Problem Number : 11880
//Problem Title : °³¹Ì
//Problem Link : https://www.acmicpc.net/problem/11880

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
		ll a, b, c;

		cin >> a >> b >> c;

		ll x = a + b;
		ll y = b + c;
		ll z = a + c;

		cout << min({ a * a + y * y, x * x + c * c , z * z + b * b }) << '\n';
	}
	
	return 0;
}