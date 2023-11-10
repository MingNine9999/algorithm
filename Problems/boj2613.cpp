//Problem Number : 2613
//Problem Title : 숫자구슬
//Problem Link : https://www.acmicpc.net/problem/2613

#include <iostream>

using namespace std;

int n, m;
int arr[311];
int divi[30100][311];

int parametric(int mini, int maxi) 
{
	if (mini >= maxi) {
		return maxi;
	}

	int mid = (mini + maxi) / 2;
	int c = 0;

	for (int i = 0; i < m; i++) {
		int sum = 0;
		while (sum + arr[c] <= mid) {
			sum += arr[c];
			
			if (n - c == m - i) {
				while (i < m) {
					divi[mid][i] = c;
					i++;
					c++;
				}
				break;
			}
			c++;
		}
		divi[mid][i] = c - 1;
	}

	if (divi[mid][m - 1] == n - 1) {
		return parametric(mini, mid);
	}
	else {
		return parametric(mid + 1, maxi);
	}	
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int mini = 0, maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (mini < arr[i]) {
			mini = arr[i];
		}
		maxi += arr[i];
	}

	int ans = parametric(mini, maxi);

	cout << ans << "\n" << divi[ans][0] + 1;
	for (int i = 1; i < m; i++) {
		cout << " " << divi[ans][i] - divi[ans][i - 1];
	}

	return 0;
}
