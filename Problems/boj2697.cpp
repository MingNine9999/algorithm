//Problem Number : 2697
//Problem Title : 다음수 구하기
//Problem Link : https://www.acmicpc.net/problem/2697

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char num[81];

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}


int main() {
	int t;
	cin >> t;
	
	while (t--) {
		cin >> num;

		int len = strlen(num);
		int check = 0;
		for (int i = len - 2; i >= 0; i--) {
			int m = 10 + '0', c = 0;
			for (int j = len - 1; j > i; j--) {
				if (num[i] < num[j] && num[j] < m) {
					m = num[j];
					c = j;
				}
			}
			if (c) {
				num[c] = num[i];
				num[i] = m;
				sort(num + i + 1, num + len);
				check++;
				break;
			}
		}
		if (check) {
			cout << num << "\n";
		}
		else {
			cout << "BIGGEST" << "\n";
		}

	}

	return 0;
}