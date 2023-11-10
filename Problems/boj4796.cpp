//Problem Number : 4796
//Problem Title : 캠핑
//Problem Link : https://www.acmicpc.net/problem/4796

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cs = 1;
	while (cs) {
		int L, P, V;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) {
			break;
		}

		int ans = 0;
		ans = V / P * L;
		int tmp = V % P;
		if (tmp >= L) {
			ans += L;
		}
		else {
			ans += tmp;
		}

		cout << "Case " << cs << ": " << ans << "\n";
		cs++;
	}

	return 0;
}