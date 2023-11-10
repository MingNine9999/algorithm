//Problem Number : 2609
//Problem Title : 최대공약수와 최소공배수
//Problem Link : https://www.acmicpc.net/problem/2609

#include <iostream>

using namespace std;

int gcd(int p, int q) {
	if (q == 0) {
		return p;
	}
	return gcd(q, p%q);
}

int main() {
	int n, m;
	cin >> n >> m;

	int gcdVal = gcd(n, m);
	cout << gcdVal << "\n";
	cout << n * m / gcdVal;

	return 0;
}