//Problem Number : 10825
//Problem Title : 국영수
//Problem Link : https://www.acmicpc.net/problem/10825

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct score {
	char name[11];
	int k;
	int e;
	int m;
} score;

bool compare(score &a, score &b) {
	if (a.k == b.k) {
		if (a.e == b.e) {
			if (a.m == b.m) {
				for (int i = 0; i < 10; i++) {
					if (a.name[i] == b.name[i]) {
						continue;
					}
					else {
						return a.name[i] < b.name[i];
					}
				}
			}
			return a.m > b.m;
		}
		return a.e < b.e;
	}
	else {
		return a.k > b.k;
	}
}

score student[100001];

int main() {
	int n;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%s%d%d%d", student[i].name, &student[i].k, &student[i].e, &student[i].m);
	}

	sort(student, student + n, compare);

	for (int i = 0; i < n; i++) {
		printf("%s\n", student[i].name);
	}

	return 0;
}