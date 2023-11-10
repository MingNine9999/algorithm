//Problem Number : 14710
//Problem Title : 고장난 시계
//Problem Link : https://www.acmicpc.net/problem/14710

#include <iostream>

using namespace std;

int main() {
	int h, m;
	cin >> h >> m;

	int n = (h * 12) % 360;
	
	if (m == n) {
		cout << "O";
	}
	else {
		cout << "X";
	}

	return 0;
}