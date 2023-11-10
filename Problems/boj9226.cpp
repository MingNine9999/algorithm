//Problem Number : 9226
//Problem Title : 도깨비말
//Problem Link : https://www.acmicpc.net/problem/9226

#include <iostream>
#include <string>

using namespace std;

const char vocoid[5] = { 'a','e','i','o','u' };

int main() {
	while (1) {
		string str;
		cin >> str;
		if (str == "#") break;

		bool check = false;
		for (int i = 0; str[i] != 0; i++) {
			for (int j = 0; j < 5; j++) {
				if (str[i] == vocoid[j]) {
					if (i == 0) {
						cout << str + "ay" << "\n";
						check = true;
						break;
					}
					else {
						cout <<str.substr(i,str.size()) + str.substr(0, i) + "ay" << "\n";
						check = true;
						break;
					}
				}
			}
			if (check) {
				break;
			}
		}
		if (check == 0) {
			cout << str + "ay" << "\n";
		}


	}

	return 0;
}