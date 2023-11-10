//Problem Number : 1157
//Problem Title : 단어 공부
//Problem Link : https://www.acmicpc.net/problem/1157

#include <iostream>
#include <string>

using namespace std;

int alphabet[27];

int main() {
	string input;
	char ans;
	int max = 0;
	char tie = 0;

	cin >> input;
	
	for (int i = 0; input[i] != NULL; i++) {
		if (input[i] >= 'a' &&input[i] <= 'z') {
			alphabet[input[i] - 'a']++;
			if (max < alphabet[input[i] - 'a']) {
				max = alphabet[input[i] - 'a'];
				ans = input[i] - 'a' + 'A';
				tie = 0;
			}
			else if (max == alphabet[input[i] - 'a']) {
				tie = input[i] - 'a' + 'A';
			}
		}
		else if(input[i] >= 'A' &&input[i] <= 'Z') {
			alphabet[input[i] - 'A']++;
			if (max < alphabet[input[i] - 'A']) {
				max = alphabet[input[i] - 'A'];
				ans = input[i];
				tie = 0;
			}
			else if (max == alphabet[input[i] - 'A']) {
				tie = input[i];
			}
		}
	}

	if (tie) {
		cout << "?" ;
	}
	else {
		if(ans)
		cout << ans;
	}

	return 0;
}