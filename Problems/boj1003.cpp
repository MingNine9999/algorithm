//Problem Number : 1003
//Problem Title : 피보나치 함수
//Problem Link : https://www.acmicpc.net/problem/1003

#include <iostream>

using namespace std;

int fibo[41][2];

int main() {

	int t;

	cin >> t;

	fibo[0][0] = 1;
	fibo[0][1] = 0;
	fibo[1][0] = 0;
	fibo[1][1] = 1;

	for (int i = 2; i < 41; i++) {
		fibo[i][0] = fibo[i - 2][0] + fibo[i - 1][0];
		fibo[i][1] = fibo[i - 2][1] + fibo[i - 1][1];		
	}

	while (t--) {
		int n;

		cin >> n;

		cout << fibo[n][0] << " " << fibo[n][1] << "\n";

	}

	return 0;
}