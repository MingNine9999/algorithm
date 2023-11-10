//Problem Number : 1927
//Problem Title : 최소 힙
//Problem Link : https://www.acmicpc.net/problem/1927

#include <iostream>

using namespace std;

int heap[100001] = { 0, };
int siz = 1;

void heap_insert(int n) {
	int node = siz;
	heap[node] = n;
	siz++;

	while (node / 2 >= 1) {
		if (heap[node / 2] > heap[node]) {
			swap(heap[node / 2], heap[node]);
			node /= 2;
		}
		else break;
	}


	return;
}

int heap_pop() {
	int ret = heap[1];
	heap[1] = heap[siz - 1];
	heap[siz - 1] = 0;
	siz--;

	int node = 1;
	while (node * 2 + 1 < siz) {
		if (heap[node * 2 + 1] != 0 && heap[node * 2] > heap[node * 2 + 1] && heap[node * 2 + 1] < heap[node]) {
			swap(heap[node * 2 + 1], heap[node]);
			node = node * 2 + 1;
		}
		else if (heap[node * 2] < heap[node]) {
			swap(heap[node * 2], heap[node]);
			node *= 2;
		}
		else break;
	}
	if (node * 2 < siz && heap[node * 2] < heap[node]) {
		swap(heap[node * 2], heap[node]);
	}

	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int com;
	for (int i = 0; i < n; i++) {
		cin >> com;
		if (com == 0) {
			if (siz == 1) {
				cout << 0 << "\n";
			}
			else {
				cout << heap_pop() << "\n";
			}
		}
		else {
			heap_insert(com);
		}
	}

	return 0;
}