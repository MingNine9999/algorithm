//Problem Number : 1449
//Problem Title : 수리공 항승
//Problem Link : https://www.acmicpc.net/problem/1449

#include <iostream>


using namespace std;


int water[1001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		water[input]++;
	}

	int ans = 0;
	for (int i = 1; i <= 1000; i++) {
		if (water[i] == 1) {
			ans++;
			for (int tape = 0; tape < l; tape++) {
				if (water[i + tape] == 1) {
					water[i + tape] = 0;
				}
			}
			i += l - 1;
		}
	}

	cout << ans;

	return 0;
}