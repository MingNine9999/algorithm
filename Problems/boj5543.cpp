//Problem Number : 5543
//Problem Title : 상근날드 
//Problem Link : https://www.acmicpc.net/problem/5543

#include <iostream>
#include <algorithm>

#define INF 1234567890

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a = INF, b = INF;
	int in;
	for (int i = 0; i < 3; i++) {
		cin >> in;
		a = min(a, in);
	}
	for (int i = 0; i < 2; i++) {
		cin >> in;
		b = min(b, in);
	}

	cout << a + b - 50;

	return 0;
}