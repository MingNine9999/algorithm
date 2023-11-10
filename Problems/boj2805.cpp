//Problem Number : 2805
//Problem Title : 나무 자르기
//Problem Link : https://www.acmicpc.net/problem/2805

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;
vector<int> tree;
 
ll par(ll l, ll r)
{
	if (l >= r) {
		return l;
	}

	ll mid = (l + r + 1) / 2;
	ll t = 0;
	for (int i = 0; i < n; i++) {
		t += max((long long)tree[i] - mid, (long long)0);
	}

	if (t == m) {
		return mid;
	}
	else if (t > m) {
		return par(mid, r);
	}
	else {
		return par(l, mid - 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int maxi = -1;
	cin >> n >> m;
	tree.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> tree[i];

		maxi = max(maxi, tree[i]);
	}

	cout << par(0, maxi);
	
	return 0;
}