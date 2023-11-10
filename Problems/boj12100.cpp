//Problem Number : 12100
//Problem Title : 2048 (Easy)
//Problem Link : https://www.acmicpc.net/problem/12100

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

vector<vector<int>> moveL(vector<vector<int>> mat)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			int k = j + 1;
			while (k <= n && mat[i][k] == 0) {
				k++;
			}
			if (k > n) break;

			if (mat[i][j] == mat[i][k]) {
				mat[i][j] *= 2;
				mat[i][k] = 0;
				j = k;
			}
		}

		for (int j = 1; j < n; j++) {
			if (mat[i][j] == 0) {
				int k = j + 1;
				while (k <= n && mat[i][k] == 0) {
					k++;
				}
				mat[i][j] = mat[i][k];
				mat[i][k] = 0;
			}
		}
	}

	return mat;
}

vector<vector<int>> moveR(vector<vector<int>> mat)
{
	for (int i = 1; i <= n; i++) {
		for (int j = n; j > 1; j--) {
			int k = j - 1;
			while (k >= 1 && mat[i][k] == 0) {
				k--;
			}
			if (k < 1) break;

			if (mat[i][j] == mat[i][k]) {
				mat[i][j] *= 2;
				mat[i][k] = 0;
				j = k;
			}
		}

		for (int j = n; j > 1; j--) {
			if (mat[i][j] == 0) {
				int k = j - 1;
				while (k > 0 && mat[i][k] == 0) {
					k--;
				}
				mat[i][j] = mat[i][k];
				mat[i][k] = 0;
			}
		}
	}

	return mat;
}

vector<vector<int>> moveU(vector<vector<int>> mat)
{
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i < n; i++) {
			int k = i + 1;
			while (k <= n && mat[k][j] == 0) {
				k++;
			}
			if (k > n) break;

			if (mat[i][j] == mat[k][j]) {
				mat[i][j] *= 2;
				mat[k][j] = 0;
				i = k;
			}
		}

		for (int i = 1; i < n; i++) {
			if (mat[i][j] == 0) {
				int k = i + 1;
				while (k <= n && mat[k][j] == 0) {
					k++;
				}
				mat[i][j] = mat[k][j];
				mat[k][j] = 0;
			}
		}
	}

	return mat;
}

vector<vector<int>> moveD(vector<vector<int>> mat)
{
	for (int j = 1; j <= n; j++) {
		for (int i = n; i > 1; i--) {
			int k = i - 1;
			while (k >= 1 && mat[k][j] == 0) {
				k--;
			}
			if (k < 1) break;

			if (mat[i][j] == mat[k][j]) {
				mat[i][j] *= 2;
				mat[k][j] = 0;
				i = k;
			}
		}

		for (int i = n; i > 1; i--) {
			if (mat[i][j] == 0) {
				int k = i - 1;
				while (k > 0 && mat[k][j] == 0) {
					k--;
				}
				mat[i][j] = mat[k][j];
				mat[k][j] = 0;
			}
		}
	}

	return mat;
}

int solve(int t, vector<vector<int>> mat)
{
	int ret = 0;

	if (t == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ret = max(ret, mat[i][j]);
			}
		}

		return ret;
	}

	vector<vector<int>> tmp;

	tmp = moveL(mat);
	ret = max(ret, solve(t - 1, tmp));
	tmp = moveR(mat);
	ret = max(ret, solve(t - 1, tmp));
	
	tmp = moveU(mat);
	ret = max(ret, solve(t - 1, tmp));
	tmp = moveD(mat);
	ret = max(ret, solve(t - 1, tmp));

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int> > mat;

	cin >> n;
	mat.resize(n + 2);
	for (int i = 1; i <= n; i++) {
		mat[i].resize(n + 2, 0);
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	mat[0].resize(n + 2, 0);
	mat[n + 1].resize(n + 2, 0);

	cout << solve(5, mat);

	return 0;
}