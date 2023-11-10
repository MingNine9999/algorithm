//Problem Number : 1799
//Problem Title : 비숍
//Problem Link : https://www.acmicpc.net/problem/1799

#include <iostream>
#include <algorithm>
#include <vector>

#define MP make_pair

using namespace std;

int n;
int MAP[15][15];
int check[15][15];
vector<pair<int, int> > vec[2];
int MAX[2];

const int goY[] = { 1,1,-1,-1 };
const int goX[] = { 1,-1,-1,1 };

int dfs(int y, int x, int v, int M, int bw)
{
	if (check[y][x]) return 0;
//	if (MAX[bw] > M + vec[bw].size() - v - 1) return -1;

	int ret = 0;

	check[y][x] += 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; ; j++) {
			if (y + goY[i] * j > n || y + goY[i] * j < 1 || x + goX[i] * j > n || x + goX[i] * j < 1) {
				break;
			}

			check[y + goY[i] * j][x + goX[i] * j] += 1;
		}
	}

	for (int i = v + 1; i < vec[bw].size(); i++) {
		ret = max(ret, dfs(vec[bw][i].first, vec[bw][i].second, i, M + 1, bw));
	}

	check[y][x] -= 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; ; j++) {
			if (y + goY[i] * j > n || y + goY[i] * j < 1 || x + goX[i] * j > n || x + goX[i] * j < 1) {
				break;
			}

			check[y + goY[i] * j][x + goX[i] * j] -= 1;
		}
	}

	return ret + 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> MAP[i][j];

			if (MAP[i][j]) {
				int a = i - j;
				if (a > 0) {
					a = (i - j) % 2;
				}
				else {
					a = (j - i) % 2;
				}
				vec[a].push_back(MP(i, j));
			}
		}
	}

	for (int bw = 0; bw <= 1; bw++) { 
		for (int i = 0; i < vec[bw].size(); i++) {
			MAX[bw] = max(MAX[bw], dfs(vec[bw][i].first, vec[bw][i].second, i, 1, bw));
		}
	}

	cout << MAX[0] + MAX[1];

	return 0;
}
/*
   10
   1 1 1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1 1 1
   */
