#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
	long long siz;
	long long t = 0;
	vector<pair<int, int>> v;
	vector<int> rest;
	
	for (int i = 0; i < food_times.size(); i++) {
		v.push_back({ food_times[i], i + 1 });
	}
	siz = v.size();
	sort(v.begin(), v.end());

	int idx = 0;
	for (int i = 0; i < v.size(); i++) {
		if (k < siz * (v[i].first - t)) {
			idx = i;

			break;
		}
		
		k -= siz * (v[i].first - t);
		t = v[i].first;
		siz--;
	}

	for (int i = idx; i < v.size(); i++) {
		rest.push_back(v[i].second);
	}

	sort(rest.begin(), rest.end());

	if (siz == 0) {
		answer = -1;
	}
	else {
		answer = rest[k % siz];
	}

    return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	long long k;
	vector<int> fts;

	cin >> n;
	fts.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> fts[i];
	}
	cin >> k;

	cout << solution(fts, k);

	return 0;
}