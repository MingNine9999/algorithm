//Problem Number : 17281
//Problem Title : ⚾
//Problem Link : https://www.acmicpc.net/problem/17281

#include <iostream>
#include <algorithm>

using namespace std;

int hit[55][11];
int check[11];
int lineup[11];
int bound[55];
int bb;
int ans;
int n;

int score()
{
	int ret = 0;
	int b = bb;
	int c = 0;

	for (int i = 0; i < n; i++) {
		if (ret + b < ans) break;
		b -= bound[i];
		
		int out = 0;
		int base[4] = { 0 };

		for (int j = c; out < 3; j++) {
			int p = lineup[j % 9];
			if (hit[i][p] == 0) {
				out++;
			}
			else {
				for (int k = 3; k > 0; k--) {
					if (base[k] == 0) continue;
					int r = k + hit[i][p] < 4 ? k + hit[i][p] : 0;

					base[k] = 0;
					base[r] += 1;
				}
				base[hit[i][p] % 4] += 1;
			}

			c = j + 1;
		}

		ret += base[0];
	}

	return ret;
}

void dfs(int v)
{
	if (v == 9) {
		ans = max(ans, score());
		return;
	}
	if (v == 3) {
		dfs(v + 1);
		return;
	}

	for (int i = 1; i < 9; i++) {
		if (check[i]) continue;

		check[i] = 1;
		lineup[v] = i;
		dfs(v + 1);
		check[i] = 0;
	}

	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int o = 0;
		for (int j = 0; j < 9; j++) {
			cin >> hit[i][j];
			bound[i] += hit[i][j];
			if (hit[i][j] == 0) {
				o++;
			}
		}
		bound[i] = bound[i] < 4 ? 0 : bound[i] - 3;
		if (o == 2) {
			bound[i] *= 2;
		}
		else if (o == 1) {
			bound[i] *= 3;
		}
		bb += bound[i];
	}

	lineup[3] = 0;
	check[0] = 1;
	
	dfs(0);

	cout << ans;

	return 0;
}
