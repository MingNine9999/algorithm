//Problem Number : 7770
//Problem Title : 아즈텍 피라미드
//Problem Link : https://www.acmicpc.net/problem/7770

#include <iostream>

using namespace std;

int main() {
	int n, h = 0, check = 0;
	cin >> n;
	
	while (n >= check) {
		h++;
		int j,i = 1;
		
		for (j = 1; j < h; j++) {
			i += j * 4;
		}
		check = i + j * 4;

		n -= i;
	}

	cout << h;

	return 0;
}