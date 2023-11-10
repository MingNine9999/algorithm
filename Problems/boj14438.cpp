//Problem Number : 14438
//Problem Title : ¼ö¿­°ú Äõ¸® 17
//Problem Link : https://www.acmicpc.net/problem/14438

#include <iostream>
#include <algorithm>

#define INF 1234567890

using namespace std;

int segTree[333333];
int siz;

void segInit(int n)
{
	siz = 1;
	while (siz < n) {
		siz <<= 1;
	}

	for (int i = 0; i < n; i++) {
		cin >> segTree[siz + i];
	}
	for (int i = n; i < siz; i++) {
		segTree[siz + i] = INF;
	}

	for (int i = siz - 1; i > 0; i--) {
		segTree[i] = (segTree[i * 2] < segTree[i * 2 + 1] ? segTree[i * 2] : segTree[i * 2 + 1]);
	}

	return;
}

void segUpdate(int pos, int v)
{
	pos += siz;
	segTree[pos] = v;

	for (int i = (pos >> 1); i > 0; i >>= 1) {
		int t = segTree[i];

		segTree[i] = (segTree[i * 2] < segTree[i * 2 + 1] ? segTree[i * 2] : segTree[i * 2 + 1]);
		if (t == segTree[i]) {
			break;
		}
	}
}

int query(int s, int e, int l, int r, int pos)
{
	if (r < s || l > e) {
		return INF;
	}

	if (s <= l && r <= e) {
		return segTree[pos];
	}
	else {
		int m = (l + r) / 2;

		return min(query(s, e, l, m, pos << 1), query(s, e, m + 1, r, (pos << 1) + 1));
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	
	cin >> n;
	segInit(n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int c, s, e;

		cin >> c >> s >> e;

		if (c == 1) {
			segUpdate(s - 1, e);
		}
		else {
			cout << query(s - 1, e - 1, 0, siz - 1, 1) << '\n';
		}
	}
	
	return 0;
}