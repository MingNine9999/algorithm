//Problem Number : 2993
//Problem Title : 세 부분
//Problem Link : https://www.acmicpc.net/problem/2993

#include <iostream>
#include <string>

using namespace std;

void reverse(string& str, int l, int r)
{
	if (l == r) {
		return;
	}

	int mid = (l + r) / 2;
	string s = " ";

	for (int i = l; i <= mid; i++) {
		s[0] = str[i];
		str[i] = str[r - (i - l)];
		str[r - (i - l)] = s[0];
	}
}

string func(string& str, int cnt, int start)
{
	int len = str.length();
	int f, s, t;
	f = s = t = start;

	for (int i = start; i < len; i++) {
		if (str[f] > str[i]) {
			t = s;
			s = f;
			f = i;
		}
		else if (str[f] == str[i]) {
			for (int j = 1; f - j >= 0; j++) {
				if (str[f - j] > str[i - j]) {
					t = s;
					s = f;
					f = i;
					break;
				}
				else if (str[f - j] < str[i - j]) {
					break;
				}
			}
		}
	}

	if (cnt == 0) {
		if (f == len - 1 && s == len - 2) {
			f = t;
		}
		else if (f == len - 1 || f == len - 2) {
			f = s;
		}

		reverse(str, start, f);
		return func(str, 1, f + 1);
	}
	else {
		if (f == len - 1) {
			f = s;
		}

		reverse(str, start, f);
		reverse(str, f + 1, len - 1);
		return str;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;

	cin >> str;

	cout << func(str, 0, 0);

	return 0;
}