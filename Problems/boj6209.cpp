//Problem Number : 6209
//Problem Title : 제자리 멀리뛰기 
//Problem Link : https://www.acmicpc.net/problem/6209

#include <iostream>
#include <algorithm>

using namespace std;

int d, n, m;
int a[55555];

int possible(int dis)
{
	int s = 0, des = 1;
	int ret = m;

	while (des <= n) {
		if (a[des] - a[s] < dis) {
			ret--;
			des++;
		}
		else {
			s = des;
			des++;
		}

		if (ret < 0) break;
	}

	return ret < 0 ? 0 : 1;
}

int parametric()
{
	int l = 1, r = d;
	int mid;

	while (l < r) {
		mid = (l + r + 1) / 2;
		
		if (possible(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}

	return l;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> d >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a, a + n + 1);

	cout << parametric();

	return 0;
}