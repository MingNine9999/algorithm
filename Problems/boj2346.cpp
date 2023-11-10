//Problem Number : 2346
//Problem Title : 풍선 터뜨리기
//Problem Link : https://www.acmicpc.net/problem/2346

#include <iostream>
#include <list>
#include <map>

using namespace std;

list<pair<int, int> > l;

int main() {
	int n;
	cin >> n;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		pair<int, int> p = make_pair(i + 1, input);
		l.push_back(p);
	}

	list< pair<int, int> >::iterator it = l.begin();
	list< pair<int, int> >::iterator tmp;

	int next = 0;
	while (1) {
		cout << it->first << " ";
		next = it->second;
		it = l.erase(it);
		if (l.size() == 0) {
			break;
		}
		if (it == l.end()) {
			it = l.begin();
		}

		if (next < 0) {
			while (next++) {
				if (it == l.begin()) {
					it = l.end();
				}
				it--;
			}
		}
		else {
			next--;
			while (next--) {
				it++;
				if (it == l.end()) {
					it = l.begin();
				}
			}
		}
		
	}

	return 0;
}