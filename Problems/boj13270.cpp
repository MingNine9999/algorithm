//Problem Number : 13270
//Problem Title : 피보나치 치킨
//Problem Link : https://www.acmicpc.net/problem/13270

#include <iostream>
#include <algorithm>

using namespace std;

struct chick {
	int man;
	int ch;
	double rate;
};

bool cmp(chick a, chick b) {
	return a.rate < b.rate;
}

int fibo[1001];
chick ck[1001];

int main() {
	int n;
	cin >> n;

	ck[0].ch = fibo[0] = 1;
	ck[0].man = fibo[1] = 2;
	ck[0].rate = (double)ck[0].ch / ck[0].man;


	for (int i = 2; i < 20; i++) {
		ck[i - 1].man = fibo[i] = fibo[i - 1] + fibo[i - 2];
		ck[i - 1].ch = fibo[i - 1];
		ck[i - 1].rate = (double)ck[i - 1].ch / ck[i - 1].man;
	}

	sort(ck, ck + 19, cmp);


	int minCheck = n, maxCheck = n;

	int minChick = 0, maxChick = 0;

	while (minCheck) {
		int check = 0;
		for (int j = 0; j < 19; j++) {
			if (ck[j].man <= minCheck && minCheck - ck[j].man != 1) {
				check = j;
				break;
			}
		}

		minCheck -= ck[check].man;
		minChick += ck[check].ch;
	}

	while (maxCheck) {
		int check = 0;
		for (int j = 18; j >= 0; j--) {
			if (ck[j].man <= maxCheck && maxCheck - ck[j].man != 1) {
				check = j;
				break;
			}
		}

		maxCheck -= ck[check].man;
		maxChick += ck[check].ch;
	}


	cout << minChick << " " << maxChick;

	return 0;
}