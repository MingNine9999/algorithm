//Problem Number : 1855
//Problem Title : 암호
//Problem Link : https://www.acmicpc.net/problem/1855

#include <iostream>
#include <string>

using namespace std;

char table[201][201];

int main() {
	int k;
	string str;

	cin >> k >> str;

	int h = 0;
	int v = 0;

	for (int i = 0; str[i] != 0; i++) {
		table[h][v] = str[i];

		if ((i + 1) % k == 0) {
			h++;
		}
		else {
			if (h % 2) {
				v--;
			}
			else {
				v++;
			}
		}
	}

	string ans;
	for (v = 0; v < k; v++) {
		for (h = 0; table[h][v] != 0; h++) {
			ans.push_back(table[h][v]);
		}
	}

	cout << ans;

	return 0;
}