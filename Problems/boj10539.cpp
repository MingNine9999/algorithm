//Problem Number : 10539
//Problem Title : 수빈이와 수열
//Problem Link : https://www.acmicpc.net/problem/10539

#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

int a[111];
int b[111];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll total = 0;

	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		b[i] = (a[i] * i) - total;
		total = a[i] * i;
	}

	for (int i = 1; i <= n; i++) {
		cout << b[i] << ' ';
	}

	return 0;
}