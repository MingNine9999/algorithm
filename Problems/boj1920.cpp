//Problem Number : 1920
//Problem Title : 수 찾기
//Problem Link : https://www.acmicpc.net/problem/1920

#include <iostream>
#include <set>

using namespace std;

set<int> s;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	int in;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		s.insert(in);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> in;
		if (s.find(in) == s.end()) {
			cout << 0 << "\n";
		}
		else {
			cout << 1 << "\n";
		}
	}

	return 0;
}