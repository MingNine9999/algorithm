//Problem Number : 2997
//Problem Title : 네 번째 수
//Problem Link : https://www.acmicpc.net/problem/2997

#include <iostream>
#include <algorithm>

using namespace std;

int num[3];

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> num[i];
	}

	sort(num, num + 3);


	int term1 = num[1] - num[0];
	int term2 = num[2] - num[1];

	if (term1 == term2) {
		cout << num[2] + term1;
	}
	else if (term1 < term2) {
		cout << num[1] + term1;
	}
	else {
		cout << num[0] + term2;
	}

	return 0;
}