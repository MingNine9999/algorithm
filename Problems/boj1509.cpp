//Problem Number : 1509
//Problem Title : 팰린드롬 분할
//Problem Link : https://www.acmicpc.net/problem/1509

#include <iostream>
#include <algorithm>

using namespace std;

char str[2502];
int p[2502][2502];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> str;

	for (n = 0; str[n] != 0; n++) {
		p[n][n] = 1;
		if (str[n] == str[n + 1]) {
			p[n][n + 1] = 1;
		}
	}
    if (p[0][1] == 0) {
        p[0][1] = 2;
    }

	for (int gap = 2; gap < n; gap++) {
		for (int i = 0; i + gap < n; i++) {
			int j = i + gap;
			if (str[i] == str[j] && p[i + 1][j - 1]) {
				p[i][j] = 1;
			}
		}
        
        if (p[0][gap] != 1) {
            p[0][gap] = p[0][gap - 1] + 1;
            for (int i = 2; i <= gap; i++) {
                if (p[gap - i + 1][gap] == 1) {
                    p[0][gap] = min(p[0][gap], p[0][gap - i] + 1);
                }
            }
        }
	}

	cout << p[0][n - 1];

	return 0;
}
