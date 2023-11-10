//Problem Number : 2201
//Problem Title : 이친수 찾기
//Problem Link : https://www.acmicpc.net/problem/2201

#include <iostream>

using ll = long long;
using namespace std;

ll in;
ll dp[1111];
bool check[1111];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int i, c;
	ll sum = 0;

	cin >> in;
	
	dp[1] = dp[2] = 1;
	sum = dp[1] + dp[2];

	for (i = 2; sum <= in; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		sum += dp[i];
	}

	sum -= dp[--i];
	c = i;
	while (in) {
		in -= sum;
		check[i] = 1;

		while (in < sum) {
			sum -= dp[--i];
		}
	}
	
	for (i = c; i > 0; i--) {
		cout << check[i] ? 1 : 0;
	}

	return 0;
}