//Problem Number : 14465
//Problem Title : 소가 길을 건너간 이유 5
//Problem Link : https://www.acmicpc.net/problem/14465

#include <iostream>
#include <algorithm>

using namespace std;

int n, k, b;
int sl[100001];

int bisec(int l, int r) {
	if (r <= l) {
		return r;
	}

	int mid = (l + r) / 2;
	int i;

	for (i = 0; i + mid <= b + 1; i++) {
		if (sl[mid + i + 1] - sl[i] > k) {
			break;
		}
	}

	if (i + mid > b + 1) {
		return bisec(mid + 1, r);
	}
	else {
		return bisec(l, mid);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k >> b;
	for (int i = 0; i < b; i++) {
		cin >> sl[i];
	}

	sort(sl, sl + b + 1);
	sl[b + 1] = n + 1;

	cout << bisec(0, b);

	return 0;
}