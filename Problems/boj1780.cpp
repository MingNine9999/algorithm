//Problem Number : 1780
//Problem Title : 종이의 개수
//Problem Link : https://www.acmicpc.net/problem/1780

#include <iostream>
#include <algorithm>

using namespace std;

struct mzo {
	int m;
	int z;
	int o;
};

int P[6666][6666];

mzo nop(int y, int x, int l)
{
	int base = P[y][x];
	int check = 1;
	mzo ret = { 0,0,0 };

	for (int i = 0; i < l && check; i++) {
		for (int j = 0; j < l && check; j++) {
			if (base != P[y + i][x + j]) {
				check = 0;
			}
		}
	}

	if (check == 0) {
		int ll = l / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				mzo tmp = nop(y + ll * i, x + ll * j, ll);
				ret.m += tmp.m;
				ret.z += tmp.z;
				ret.o += tmp.o;
			}
		}
	}
	else {
		switch (base) {
			case -1 : 
				ret.m = 1;
				break;
			case 0 :
				ret.z = 1;
				break;
			case 1:
				ret.o = 1;
				break;
		}
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> P[i][j];
		}
	}

	mzo ans = nop(1, 1, n);
	cout << ans.m << '\n';
	cout << ans.z << '\n';
	cout << ans.o << '\n';


	return 0;
}