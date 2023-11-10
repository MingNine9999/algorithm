//Problem Number : ??
//Problem Title : 튜플
//Problem Link : https://programmers.co.kr/learn/courses/30/lessons/64065

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

bool cmp(set<int> a, set<int> b)
{
	return a.size() < b.size();
}

vector<int> solution(string s)
{
	vector<int> answer;
	vector<set<int> > v;
	set<int> ss;

	int x = 0;
	int c = 0;
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == '{') {
			c = 1;
		}
		else if (s[i] == '}') {
			ss.insert(x);
			x = 0;
			v.push_back(ss);
			c = 0;
			ss.clear();
		}
		else if (s[i] == ',' && c == 1) {
			ss.insert(x);
			x = 0;
		}
		else if (c == 1) {
			x *= 10;
			x += s[i] - '0';
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < answer.size(); j++) {
			x = answer[j];
			v[i].erase(x);
		}
		answer.push_back(*v[i].begin());
	}
	
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	vector<int> ans;

	cin >> s;

	ans = solution(s);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}