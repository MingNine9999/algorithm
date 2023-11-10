//Problem Number : 11652
//Problem Title : 카드
//Problem Link : https://www.acmicpc.net/problem/11652

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<long long, int> m;

int main() {
	int n;
	cin >> n;

	long long num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		m[num]++;
	}


	pair<long long, int> max = make_pair(0, 0);

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second > max.second) {
			max.first = it->first;
			max.second = it->second;
		}
		else if (it->second == max.second && it->first < max.first) {
			max.first = it->first;
		}
	}

	cout << max.first;

	return 0;
}