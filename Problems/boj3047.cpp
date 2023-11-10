//Problem Number : 3047
//Problem Title : ABC
//Problem Link : https://www.acmicpc.net/problem/3047

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num[3];

	cin >> num[0] >> num[1] >> num[2];
	sort(num, num + 3);

	char input[4];
	cin >> input;

	for (int i = 0; i < 3; i++) {
		cout << num[input[i] - 'A'] << " ";
	}

	return 0;
}