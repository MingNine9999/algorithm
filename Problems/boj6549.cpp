//Problem Number : 6549
//Problem Title : 히스토그램에서 가장 큰 직사각형
//Problem Link : https://www.acmicpc.net/problem/6549

#include <iostream>
#include <cstring>

using namespace std;

int height[100001];

long long maxL(long long a, long long b) {
	return a > b ? a : b;
}
int maxI(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}

long long divide(int left, int right) {
	if (left == right) {
		return height[left];
	}

	int mid = (left + right) / 2;
	long long ans = maxL(divide(left, mid), divide(mid + 1, right));

	int goL = mid;
	int goR = mid + 1;
	int minH = min(height[goL], height[goR]);
	ans = maxL(ans, (long long)minH * 2);

	while (goL > left || goR < right) {
		if (goL == left || (goL - 1 >= left && goR + 1 <= right && height[goL - 1] <= height[goR + 1])) {
			goR++;
			minH = min(minH, height[goR]);
			ans = maxL(ans, (long long)minH * (goR - goL + 1));
		}
		else if (goR == right || (goL - 1 >= left && goR + 1 <= right && height[goL - 1] > height[goR + 1])) {
			goL--;
			minH = min(minH, height[goL]);
			ans = maxL(ans,(long long) minH * (goR - goL + 1));
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}

		memset(height, 0, sizeof(int) * 100001);
		
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}

		cout << divide(0, n - 1) << "\n";

	}

	return 0;
}