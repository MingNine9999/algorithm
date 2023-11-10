//Problem Number : 9708
//Problem Title : 가장 긴 수열
//Problem Link : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXDNGXlKagUDFAVX&categoryId=AXDNGXlKagUDFAVX&categoryType=CODE

#include <iostream>
#include <algorithm>

using namespace std;

int a[111111];
int N[1111111];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int TC;

	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		int n;
		int MAX = 0;
		int ans = 0;

		fill(N, N + 1111111, 0);

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			N[a[i]] = 1;

			MAX = max(MAX, a[i]);
		}

		sort(a, a + n);

		for (int i = 0; i < n; i++) {
			for (int j = 2; a[i] * j <= MAX; j++) {
				if (N[a[i] * j]) {
					N[a[i] * j] = max(N[a[i] * j], N[a[i]] + 1);
				}
			}

			ans = max(ans, N[a[i]]);
		}
		

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
