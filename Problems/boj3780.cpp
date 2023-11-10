//Problem Number : 3780
//Problem Title : 네트워크 연결
//Problem Link : https://www.acmicpc.net/problem/3780

#include <iostream>
#include <algorithm>

#define MOD 1000
#define ABS(a) ((a) > 0 ? (a) : -(a))

using namespace std;

pair<int, int> p[22222];
int dis[22222];

pair<int, int> find(int v)
{
	if (p[v].first == v) {
		return p[v];
	}
	
	pair<int, int> t = find(p[v].first);
	p[v].first = t.first;
	p[v].second += t.second;

	return p[v];
}

void uni(int a, int b)
{
	int pa = find(a).first;
	
	p[pa].first = b;
	p[pa].second = ABS(pa - b) % 1000;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TC;

	cin >> TC;
	while (TC--) {
		int n;
		char com;
		int a, b;

		cin >> n;

		for (int i = 1; i <= n; i++) {
			p[i].first = i;
			p[i].second = 0;
		}

		while (1) {
			cin >> com;

			if (com == 'O') {
				break;
			}
			else if (com == 'I') {
				cin >> a >> b;
				uni(a, b);
			}
			else if (com == 'E') {
				cin >> a;
				cout << find(a).second << '\n';
			}
		}

	}

	return 0;
}