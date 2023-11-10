//Problem Number : 2647
//Problem Title : 검은점과 하얀점 연결 
//Problem Link : https://www.acmicpc.net/problem/2647

#include <iostream>
#include <algorithm>

#define INF 1234567890

using namespace std;

char str[111];
int memo[111][111];
int height[111][111];
int con[111][111];

int rec(int s, int e)
{
	if (e - s < 1) return 0;
	if (memo[s][e]) return memo[s][e];

	int ret = INF;
	int b = 0, w = 0;
	
	for (int i = s + 1; i <= e; i++) {
		if (str[s] != str[i] && b == w) {
			int t = rec(s + 1, i - 1) + rec(i + 1, e);
			int si = i - s + (height[s + 1][i - 1] + 1) * 2;

			if (ret > t + si) {
				ret = t + si;
				height[s][e] = max(height[s + 1][i - 1] + 1, height[i + 1][e]);
				con[s][e] = i;
			}
		}

		if (str[i] == '0') {
			w++;
		}
		else {
			b++;
		}
	}

	return memo[s][e] = ret;
}

void connect(int s, int e)
{
	if (e - s < 1) return;

	cout << s << ' ' << con[s][e] << '\n';
	connect(s + 1, con[s][e] - 1);
	connect(con[s][e] + 1, e);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	cin >> str + 1;
	
	cout << rec(1, n) << '\n';
	connect(1, n);

	return 0;
}