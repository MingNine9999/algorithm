//Problem Number : 1300
//Problem Title : K번째 수
//Problem Link : https://www.acmicpc.net/problem/1300

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;

	cin >> n;
	cin >> k;

	int l = 1, r = k;
	int mid;
    int ans;
	long long cnt;

	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0;

		for (int i = 1; i <= n; i++) {
			cnt += min(n, mid / i);
		}

		if (cnt >= k) {
            ans = mid;
			r = mid - 1;
		}
		else {
            l = mid + 1;
        }
	}

	cout << ans;

	return 0;
}