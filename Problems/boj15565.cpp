//Problem Number : 15565
//Problem Title : 귀여운 라이언
//Problem Link : https://www.acmicpc.net/problem/15565

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int a[1111111];
queue<int> window;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	int r = 0;
	int MIN = 1234567890;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		window.push(a[i]);
		if (a[i] == 1) {
			r++;

			if (r == k) {
				while (window.front() != 1) {
					window.pop();
				}
				MIN = min(MIN, (int)window.size());

				window.pop();
				r--;
			}
		}
	}

	if (MIN >= (int)1e6 + 1) {
		cout << -1;
	}
	else {
		cout << MIN;
	}

	return 0;
}