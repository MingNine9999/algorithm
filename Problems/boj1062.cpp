//Problem Number : 1062
//Problem Title : 가르침
//Problem Link : https://www.acmicpc.net/problem/1062

#include <iostream>
#include <string>
#include <algorithm>

#define ctoi(c) ((c) - 'a')

using namespace std;

int n, k;
string str[51];
int check[51];
char alpha[27];

int func(int depth, int a, int pos)
{
	int ret = 0;

	if (depth == k) {
		for (int i = 0; i < n; i++) {
			if ((check[i] & a) == check[i]) {
				ret++;
			}
		}

		return ret;
	}

	for (int i = pos + 1; i < 26; i++) {
		if (alpha[i]) {
			ret = max(ret, func(depth + 1, a | (1 << i), i));
		}
	}
	ret = max(ret, func(depth + 1, a, 26));

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> str[i];

		for (int j = 0; j < str[i].length(); j++) {
			
			int c = ctoi((int)str[i][j]);
			if (c != ctoi('a') && c != ctoi('c') && c != ctoi('i') && c != ctoi('n') && c != ctoi('t')) {
				check[i] |= 1 << c;
				alpha[c] = 1;
			}
		}

	}

	if (k < 5) {
		cout << 0;
		return 0;
	}

	cout << func(5, 0, -1);

	return 0;
}