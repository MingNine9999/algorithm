//Problem Number : 16302
//Problem Title : Jurassic Jigsaw
//Problem Link : https://www.acmicpc.net/problem/16302

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct edg {
	int s, e, v;

	bool operator <(edg a)const {
		return v > a.v;
	}
};

char str[1111][15];
priority_queue<edg> pq;
vector<edg> v[1111];
int tree[1111];
vector<edg> ans;

void push_vec(vector<edg> vv)
{
	for (auto i : vv) {
		pq.push(i);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			edg e = { i,j,0 };

			for (int k = 0; k < m; k++) {
				if (str[i][k] != str[j][k]) {
					e.v++;
				}
			}
			
			v[i].push_back(e);
		}
	}

	int cnt = 0;
	push_vec(v[0]);
	tree[0] = 1;
	for (int i = 0; i < n - 1; i++) {
		edg t = pq.top();
		pq.pop();

		if (tree[t.e] == 0) {
			push_vec(v[t.e]);
			tree[t.e] = 1;
			cnt += t.v;
			ans.push_back(t);
		}
		else {
			i--;
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].s << ' ' << ans[i].e << '\n';
	}

	return 0;
}