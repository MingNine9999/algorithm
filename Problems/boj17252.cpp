//Problem Number : 17252
//Problem Title : ป๏ป๏วั ผ๖
//Problem Link : https://www.acmicpc.net/problem/17252

#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	bool ans = true;

	cin >> n;

	if (n == 0) {
		ans = false;
	}
	while (n != 0 && ans) {
		if (n % 3 == 2) {
			ans = false;
			break;
		}
		n /= 3;
	}

	cout << (ans ? "YES" : "NO");

	return 0;
}