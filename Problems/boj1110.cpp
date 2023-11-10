//Problem Number : 1110
//Problem Title : 더하기 사이클
//Problem Link : https://www.acmicpc.net/problem/1110

#include <iostream>
#include <map>

using namespace std;

pair<int, int> num;
pair<int, int> cycle[1001];

int main() {
	int n;
	cin >> n;

	num.first = n % 10;
	num.second = n / 10;
	cycle[0] = num;

	int i = 0;
	do {
		i++;
		num.first = cycle[i - 1].first + cycle[i - 1].second;
		num.first %= 10;
		num.second = cycle[i - 1].first;
		cycle[i] = num;
	} while (cycle[0] != cycle[i]);

	cout << i;

	return 0;
}