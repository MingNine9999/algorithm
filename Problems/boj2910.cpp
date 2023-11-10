//Problem Number : 2910
//Problem Title : 빈도 정렬
//Problem Link : https://www.acmicpc.net/problem/2910

#include <iostream>
#include <algorithm>

using namespace std;

struct tmp {
	int num;
	int quantity;
	int order;
};

bool cmp(tmp a, tmp b) {
	if (a.quantity == b.quantity) {
		return a.order < b.order;
	}

	return a.quantity > b.quantity;
}

tmp arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c;
	cin >> n >> c;

	int input;
	int order = 0;
	int j;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (j = 0; j < order; j++) {
			if (input == arr[j].num) {
				arr[j].quantity++;
				break;
			}
		}
		if (j == order) {
			arr[order].num = input;
			arr[order].order = order;
			arr[order].quantity++;
			order++;
		}
	}

	sort(arr, arr + n, cmp);
	
	for (int i = 0; i < n; i++) {
		while (arr[i].quantity--) {
			cout << arr[i].num << " ";
		}
	}

	return 0;
}