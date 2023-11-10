//Problem Number : 10942
//Problem Title : ÆÓ¸°µå·Ò?
//Problem Link : https://www.acmicpc.net/problem/10942

#include <iostream>
#include <algorithm>

using namespace std;

int a[2222];
int cmm[2222][2222];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cmm[i][i] = 1;
	}

	for (int gap = 1; gap < n; gap++) {
		for (int i = 1; i <= n - gap; i++) {
			int j = i + gap;

			if (a[i] == a[j]) {
				if (i + 1 > j - 1) {
					cmm[i][j] = 1;
				}
				else if (cmm[i + 1][j - 1]) {
					cmm[i][j] = 1;
				}
			}
		}
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		
		cin >> s >> e;
		cout << cmm[s][e] << '\n';
	}
	
	return 0;
}