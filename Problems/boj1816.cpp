//Problem Number : 1816
//Problem Title : ¾ÏÈ£ Å° 
//Problem Link : https://www.acmicpc.net/problem/1816

#include <iostream>
#include <algorithm>

#define MILLION (int)1e6

using ll = long long;
using namespace std;

int prime[333333];
int check[1111111] = { 1,1, };

void eratos()
{
	for (int i = 2; i * i <= MILLION; i++) {
		if (check[i]) continue;
		for (int j = 2; i * j <= MILLION; j++) {
			check[i * j] = 1;
		}
	}

	int p = 0;
	for (int i = 0; i <= MILLION; i++) {
		if (check[i] == 0) {
			prime[p++] = i;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	eratos();

	cin >> TC;

	while (TC--) {
		ll a;
		int c = 0;

		cin >> a;

		for (int i = 0; prime[i] != 0; i++) {
			if (a % prime[i] == 0) {
				c = 1;
				break;
			}
		}

		if (c == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}