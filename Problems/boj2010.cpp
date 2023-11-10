//Problem Number : 2010
//Problem Title : 플러그
//Problem Link : https://www.acmicpc.net/problem/2010

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int ans = 0;
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		ans += input;
	}
	
	ans = ans - n + 1;

	cout << ans;

	return 0;
}