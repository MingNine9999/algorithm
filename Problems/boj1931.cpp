//Problem Number : 1931
//Problem Title : 회의실배정
//Problem Link : https://www.acmicpc.net/problem/1931

#include <iostream>
#include <algorithm>

using namespace std;

struct time {
	int st;
	int et;
};

bool cmp(time a, time b) {
	if (a.et == b.et) {
		return a.st < b.st;
	}
	return a.et < b.et;
}

time meeting[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> meeting[i].st >> meeting[i].et;
	}

	sort(meeting, meeting + n, cmp);

	int ans = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (meeting[i].st >= t) {
			ans++;
			t = meeting[i].et;
		}
	}

	cout << ans;

	return 0;
}