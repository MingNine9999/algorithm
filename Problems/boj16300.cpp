//Problem Number : 16300
//Problem Title : H to O
//Problem Link : https://www.acmicpc.net/problem/16300

#include <iostream>
#include <cstdlib>
#include <algorithm>

#define ISNUM(a) ('0' <= (a) && (a) <= '9')
#define A 'A'
using namespace std;

char str[3333];
char str2[3333];
int alpha[33];
int alpha2[33];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int i;

	cin >> str;
	cin >> n;
	cin >> str2;

	int check = 1;
	for (i = 0; str[i] != 0; i++) {
		if (ISNUM(str[i])) {
			if (check) continue;

			alpha[str[i - 1] - A] += atoi(str + i);
			check = 1;
		}
		else {
			if (check == 0) {
				alpha[str[i - 1] - A]++;
			}
			check = 0;
		}
	}
	if (i > 0 && !ISNUM(str[i - 1])) {
		alpha[str[i - 1] - A]++;
	}

	for (i = 0; i < 26; i++) {
		alpha[i] *= n;
	}

	check = 1;
	for (i = 0; str2[i] != 0; i++) {
		if (ISNUM(str2[i])) {
			if (check) continue;

			alpha2[str2[i - 1] - A] += atoi(str2 + i);
			check = 1;
		}
		else {
			if (check == 0) {
				alpha2[str2[i - 1] - A]++;
			}
			check = 0;
		}
	}
	if (i > 0 && !ISNUM(str2[i - 1])) {
		alpha2[str2[i - 1] - A]++;
	}

	int ans = 1234567890;
	for (int i = 0; i < 26; i++) {
		if (alpha2[i] == 0) continue;

		ans = min(ans, alpha[i] / alpha2[i]);
	}
	
	cout << ans;

	return 0;
}