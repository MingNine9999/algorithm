//Problem Number : 1431
//Problem Title : 시리얼 번호
//Problem Link : https://www.acmicpc.net/problem/1431

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string serial[1001];

bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		int aNum = 0;
		int bNum = 0;

		for (int i = 0; i < a.length(); i++) {
			if (a[i] >= '0' && a[i] <= '9') {
				aNum += a[i] - '0';
			}
			if (b[i] >= '0' && b[i] <= '9') {
				bNum += b[i] - '0';
			}
		}

		if (aNum == bNum) {
			return a < b;
		}
		else {
			return aNum < bNum;
		}
	}

	return a.length() < b.length();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}

	sort(serial, serial + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << serial[i] << "\n";
	}

	return 0;
}