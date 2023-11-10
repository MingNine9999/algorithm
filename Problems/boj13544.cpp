//Problem Number : 13544
//Problem Title : ¼ö¿­°ú Äõ¸® 3
//Problem Link : https://www.acmicpc.net/problem/13544

#include <iostream>
#include <algorithm>
#include <vector>

#define INF -1234567890

using namespace std;

vector<int> mergeTree[333333];
int siz;
 
struct Q {
	int i;
	int j;
	int k;
};

void initTree(int n)
{
	siz = 1;
	while (siz < n) {
		siz <<= 1;
	}

	for (int i = 0; i < n; i++) {
		int a;
		
		cin >> a;
		mergeTree[siz + i].push_back(a);
	}

	for (int i = siz - 1; i > 0; i--) {
		mergeTree[i].resize(mergeTree[i * 2].size() + mergeTree[i * 2 + 1].size());
		merge(mergeTree[i * 2].begin(), mergeTree[i * 2].end(), mergeTree[i * 2 + 1].begin(), mergeTree[i * 2 + 1].end(), mergeTree[i].begin());
	}
}

int query(int s, int e, int l, int r, int pos, int k)
{
	if (s > r || e < l) {
		return 0;
	}

	if (s <= l && r <= e) {
		return (int)(mergeTree[pos].size() - (upper_bound(mergeTree[pos].begin(), mergeTree[pos].end(), k) - mergeTree[pos].begin()));
	}
	else {
		return query(s, e, l, (l + r) / 2, pos * 2, k) + query(s, e, (l + r) / 2 + 1, r, pos * 2 + 1, k);
	}
}

Q trans(Q in, int l)
{
	Q ret;

	ret.i = in.i ^ l;
	ret.j = in.j ^ l;
	ret.k = in.k ^ l;

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	initTree(n);

	int m;
	cin >> m;
	Q q;
	int l = 0;
	for (int i = 0; i < m; i++) {
		cin >> q.i >> q.j >> q.k;

		q = trans(q, l);

		l = query(q.i - 1, q.j - 1, 0, siz - 1, 1, q.k);
		cout << l << '\n';
	}

	return 0;
}