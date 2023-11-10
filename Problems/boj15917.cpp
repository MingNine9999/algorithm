//Problem Number : 15917
//Problem Title : 노솔브 방지문제야!!
//Problem Link : https://www.acmicpc.net/problem/15917

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Q;
	int a;

	cin >> Q;
	while (Q--) {
		cin >> a;

		cout << ((a & (-a)) == a) << '\n';
	}

	return 0;
}