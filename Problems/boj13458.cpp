//Problem Number : 13458
//Problem Title : 시험 감독
//Problem Link : https://www.acmicpc.net/problem/13458

#include <iostream>

using namespace std;

int room[1000001];
int D[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> room[i];
	}
	int mainD, subD;
	cin >> mainD >> subD;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		room[i] -= mainD;
		D[i]++;
		
		if (room[i] > 0) {
			D[i] += room[i] / subD;
			if (room[i] % subD) {
				D[i]++;
			}
		}
		ans += D[i];
	}

	cout << ans;

	return 0;
}