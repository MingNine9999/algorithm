//Problem Number : 11729
//Problem Title : 하노이 탑 이동 순서
//Problem Link : https://www.acmicpc.net/problem/11729

#include <iostream>

using namespace std;

int tower[21];

void move(int a, int b, int c) {
	int d = 3 - b - c;
	if (a == 1) {
		cout << b + 1 << " " << c + 1 << "\n";
		return;
	}
	
	move(a - 1, b, d);
	cout << b + 1 << " " << c + 1 << "\n";
	move(a - 1, d, c);

}

int main() {
	ios::sync_with_stdio(false);

	int n;

	cin >> n;
	tower[1] = 1;
	for (int i = 2; i <= n; i++) {
		tower[i] = tower[i - 1] * 2 + 1;
	}
	cout << tower[n] << "\n";

	move(n, 0, 2);

	return 0;
}
