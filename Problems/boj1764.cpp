//Problem Number : 1764
//Problem Title : 듣보잡
//Problem Link : https://www.acmicpc.net/problem/1764

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> noSee;
vector<string> noHear;
vector<string> job;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	string input;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		noSee.push_back(input);
	}

	sort(noSee.begin(), noSee.end());
	
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (binary_search(noSee.begin(), noSee.end(),input)) {
			job.push_back(input);
		}
	}
	sort(job.begin(), job.end());

	cout << job.size() << "\n";
	for (int i = 0; i < job.size(); i++) {
		cout << job[i] << "\n";
	}

	return 0;
}