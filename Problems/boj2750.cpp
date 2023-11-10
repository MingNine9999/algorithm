//Problem Number : 2750
//Problem Title : 수 정렬하기
//Problem Link : https://www.acmicpc.net/problem/2750

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void quick_sort(vector<int> &v) {
	if (v.size() == 1 || v.size() == 0) {
		return;
	}

	vector<int> small;
	vector<int> big;

	int pivot = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] <= pivot) {
			small.push_back(v[i]);
		}
		else {
			big.push_back(v[i]);
		}
	}

	quick_sort(small);
	quick_sort(big);
	int check = 0;
	for (int i = 0; i < small.size(); i++) {
		v[check] = small[i];
		check++;
	}
	v[check] = pivot;
	check++;
	for (int i = 0; i < big.size(); i++) {
		v[check] = big[i];
		check++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	quick_sort(arr);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}