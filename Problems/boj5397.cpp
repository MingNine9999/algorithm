//Problem Number : 5397
//Problem Title : 키로거
//Problem Link : https://www.acmicpc.net/problem/5397

#include <iostream>
#include <list>

using namespace std;

char str[1000001];
list<char> l;

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> str;
		list<char>::iterator it = l.begin();

		for (int i = 0; str[i] != 0; i++) {
			if (str[i] == '<') {
				if (it != l.begin()) {
					it--;
				} 
			}
			else if (str[i] == '>') {
				if (l.size() != 0 && it != l.end()) {
					it++;
				}
			}
			else if (str[i] == '-') {
				if (it != l.begin()) {
					it--;
					it = l.erase(it);
				}
			}
			else {
				l.insert(it, str[i]);
			}
		}

		while (!l.empty()) {
			cout << l.front();
			l.pop_front();
		}
		cout << "\n";
	}

	return 0;
}