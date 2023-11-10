//Problem Number : 17253
//Problem Title : 삼삼한 수 2
//Problem Link : https://www.acmicpc.net/problem/17253

#include <iostream>

#define LL long long

using namespace std;

LL sqr[55];
int save;

bool find(LL n)
{
	for (int i = save - 1; i >= 0; i--) {
		if (n >= sqr[i]) {
			n -= sqr[i];
			save = i;
			break;
		}
	}

	if (n == 0) {
		return true;
	}
	else {
		if (n >= sqr[save]) {
			return false;
		}
		return find(n);
	}
}

int main(void)
{
	LL n;

	cin >> n;
	if (n == 0) {
		cout << "NO";
		return 0;
	}

	sqr[0] = 1;
	for (int i = 1; i < 40; i++) {
		sqr[i] = sqr[i - 1] * 3;
	}
	save = 40;

	if (find(n)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}