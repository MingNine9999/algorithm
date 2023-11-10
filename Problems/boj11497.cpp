//Problem Number : 11497
//Problem Title : 통나무 건너뛰기
//Problem Link : https://www.acmicpc.net/problem/11497

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int n;
		int MIN = -1;

		cin >> n;

		v = vector<int>(n, 0);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		MIN = v[1] - v[0];
		for (int i = 2; i < n; i++) {
			MIN = max(MIN, v[i] - v[i - 2]);
		}

		cout << MIN << '\n';
	}

	return 0;
}