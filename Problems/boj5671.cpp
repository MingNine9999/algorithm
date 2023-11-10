//Problem Number : 5671
//Problem Title : 호텔 방 번호
//Problem Link : https://www.acmicpc.net/problem/5671

#include <iostream>
#include <cstdlib>

using namespace std;

int num[10];
char input[11];
char a[11];
char b[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	while (1) {
		int ans = 0;
		for (int i = 0; i < 11; i++) {
			input[i] = 0;
			a[i] = 0;
			b[i] = 0;
		}
		cin.getline(input, 25);

		if (input[0] == 0) {
			break;
		}

		bool check = false;
		int j = 0;
		for (int i = 0; input[i] != 0; i++) {
			if (input[i] == ' '){
				check = true;
				j = 0;
			}
			else if (check == false) {
				a[j++] = input[i];
			}
			else {
				b[j++] = input[i];
			}
		}

		n = atoi(a);
		m = atoi(b);


		for (int i = n; i <= m; i++) {
			for (int i = 0; i < 10; i++) {
				num[i] = 0;
			}

			int ho = i;

			while (ho > 0) {
				if (num[ho % 10] == 0) {
					num[ho % 10] = 1;
				}
				else {
					ho = -1;
					break;
				}
				ho /= 10;
			}
			if (ho != -1) {
				ans++;
			}
		}

		cout << ans << "\n";
	}
	
	return 0;
}