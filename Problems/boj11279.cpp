//Problem Number : 11279
//Problem Title : 최대 힙
//Problem Link : https://www.acmicpc.net/problem/11279

#include <iostream>

using namespace std;

int heap[100003] = { 0, };
int siz = 1;

void heap_insert(int n) {
	int node = siz;
	heap[node] = n;

	while (node / 2 >= 1) {
		if (heap[node / 2] < heap[node]) {
			swap(heap[node / 2], heap[node]);
			node /= 2;
		}
		else break;
	}

	siz++;

	return;
}

int heap_pop() {
	int ret = heap[1];
	heap[1] = heap[siz - 1];
	heap[siz - 1] = 0;

	int node = 1;
	while (node * 2 <= siz) {
		if (heap[node * 2] > heap[node * 2 + 1] && heap[node * 2] > heap[node]) {
			swap(heap[node * 2], heap[node]);
			node *= 2;
		}
		else if (heap[node * 2 + 1] > heap[node]) {
			swap(heap[node * 2 + 1], heap[node]);
			node = node * 2 + 1;
		}
		else break;
	}
	siz--;

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