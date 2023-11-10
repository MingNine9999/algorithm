//Problem Number : 2448
//Problem Title : 별 찍기 - 11
//Problem Link : https://www.acmicpc.net/problem/2448

#include <iostream>
#include <deque>
#include <cstdio>

using namespace std;

deque<char> star[3501];
const char basis_star[3][7] = { "  *   ", " * *  ", "***** " };

void print_star(int n)
{
	if (n == 3) {
		for	(int i = 0; i < 3; i++) {
			for(int j = 0; j < 6; j++) {
				star[i].push_back(basis_star[i][j]);
			}
		}
		return;
	}
	print_star(n / 2);

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				star[i + n / 2].push_back(star[i][k]);
			}
		}

		for (int j = 0; j < n / 2; j++) {
			star[i].push_front(' ');
			star[i].push_back(' ');
		}
	}
	
	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	print_star(n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			cout << star[i][j];
		}
		cout << "\n";
	}

	return 0;
}
