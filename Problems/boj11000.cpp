//Problem Number : 11000
//Problem Title : 강의실 배정
//Problem Link : https://www.acmicpc.net/problem/11000

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct time {
	int st;
	int et;
};

bool cmp(time a, time b) {
	if (a.st == b.st) {
		return a.et < b.et;
	}
	return a.st < b.st;
}

time cl[200001];
priority_queue<int, vector<int>, greater<int> > room;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cl[i].st >> cl[i].et;
	}
	
	sort(cl, cl + n, cmp);


	room.push(cl[0].et);
	for (int i = 1; i < n; i++) {
		if (cl[i].st >= room.top()) {
			room.pop();
			room.push(cl[i].et);
		}
		else {
			room.push(cl[i].et);
		}
	}

	cout << room.size();

	return 0;
}