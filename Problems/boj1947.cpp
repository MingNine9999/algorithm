//Problem Number : 1947
//Problem Title : 선물 전달
//Problem Link : https://www.acmicpc.net/problem/1947

#include <iostream>

#define MOD (int)1e9

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int a = 2, b = 1;
	
	long long ans = 0;
	for (int i = 2; i <= n; i++) {
		ans = (ans * a + b) % MOD;
		a++;
		b *= -1;
	}

	cout << ans;

	return 0;
}