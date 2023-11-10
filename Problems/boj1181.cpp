//Problem Number : 1181
//Problem Title : 단어 정렬
//Problem Link : https://www.acmicpc.net/problem/1181

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string input[20002];

bool compare(string &a, string &b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	sort(input, input + n, compare);

	for (int i = 0; i < n; i++) {
		if (input[i].compare(input[i - 1]) == 0) {
			continue;
		}
		cout << input[i] << endl;
	}
	
	return 0;
}