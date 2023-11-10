//Problem Number : 16293
//Problem Title : Appalling Architecture
//Problem Link : https://www.acmicpc.net/problem/16293

#include <iostream>

using namespace std;

char MAP[111][111];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	int cnt = 0;
	double g = 0;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> MAP[i] + 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (MAP[i][j] == '.') continue;

			g += (double)j;
			cnt++;
		}
	}

	g /= (double)cnt;

	double l, r;
	for (int i = 1; i <= m; i++) {\
		if (MAP[n][i] == '.') continue;
		else {
			l = (double)i;
			break;
		}
	}
	for (int i = m; i > 0; i--) {
		if (MAP[n][i] == '.') continue;
		else{
			r = (double)i;
			break;
		}
	}
	l -= 0.5;
	r += 0.5;

	if (l <= g && g <= r) {
		cout << "balanced";
	}
	else if (g < l) {
		cout << "left";
	}
	else {
		cout << "right";
	}

	return 0;
}