//Problem Number : 1094
//Problem Title : ¸·´ë±â
//Problem Link : https://www.acmicpc.net/problem/1094

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int ans = 0;

	cin >> n;

	for (int i = 1; i <= 64; i <<= 1) {
		if (n & i) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}