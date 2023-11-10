//Problem Number : 2915
//Problem Title : 로마 숫자 재배치 
//Problem Link : https://www.acmicpc.net/problem/2915

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char str[111];
int alpha[11];
string out;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> str;

	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == 'I') {
			alpha[0]++;
		}
		else if (str[i] == 'V') {
			alpha[1]++;
		}
		else if (str[i] == 'X') {
			alpha[2]++;
		}
		else if (str[i] == 'L') {
			alpha[3]++;
		}
		else if (str[i] == 'C') {
			alpha[4]++;
		}
	}

	if (alpha[4]) {
		out.append("XC");
		alpha[2]--;
	}
	else if (alpha[3]) {
		if (alpha[2] == 1 || (alpha[2] == 2 && alpha[0] == 1 && alpha[1] == 0)) {
			out.append("XL");
			alpha[2]--;
		}
		else {
			out.append("L");
		}
	}

	while (alpha[2] > 1) {
		out.append("X");
		alpha[2]--;
	}

	if (alpha[2] && alpha[1] == 0 && alpha[0] == 1) {
		out.append("IX");
		alpha[0]--;
		alpha[2]--;
	}
	else {
		while (alpha[2]--) {
			out.append("X");
		}
	}

	if (alpha[1]) {
		if (alpha[0] == 1) {
			out.append("IV");
			alpha[0]--;
		}
		else {
			out.append("V");
		}
	}

	while (alpha[0]--) {
		out.append("I");
	}

	cout << out << endl << endl;

	return 0;
}