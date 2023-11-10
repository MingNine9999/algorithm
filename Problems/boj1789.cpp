//Problem Number : 1789
//Problem Title : 수들의 합
//Problem Link : https://www.acmicpc.net/problem/1789

#include <iostream>

using namespace std;

int main() {
	unsigned int s;
	cin >> s;

	int i = 0;
	while (s > i) {
		i++;
		s -= i;
	}

	cout << i;
	return 0;
}