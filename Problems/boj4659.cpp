//Problem Number : 4659
//Problem Title : 비밀번호 발음하기
//Problem Link : https://www.acmicpc.net/problem/4659

#include <iostream>
#include <string>

using namespace std;

char m[5] = { 'a','e','i','o','u' };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;

	while (1) {
		cin >> input;
		if (input == "end") {				
			break;
		}

		int ja = 0;
		int mo = 0;
		bool checkMo1;
		bool check = false;
		
		for (int i = 0; input[i] != 0; i++) {
			checkMo1 = false;
			for (int j = 0; j < 5; j++) {			
				if (input[i] == m[j]) {
					checkMo1 = true;
					check = true;
					mo++;							
					ja = 0;							
					break;
				}
			}

			if (checkMo1 == false) {
				mo = 0;
				ja++;
			}

			if (input[i] == input[i + 1] && input[i] != 'e' && input[i] != 'o') {
				check = false;
				break;
			}

			if (ja >= 3 || mo >= 3) {
				check = false;
				break;
			}	
		}

		if (check) {
			cout << "<" << input << "> is acceptable.\n";
		}
		else {
			cout << "<" << input << "> is not acceptable.\n";
		}

	}

	return 0;
}