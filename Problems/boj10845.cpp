//Problem Number : 10845
//Problem Title : 큐
//Problem Link : https://www.acmicpc.net/problem/10845

#include <stdio.h>
#include <deque>
#include <string.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	deque<int> q;
	while (n--) {
		char com[10] = { 0 };
		scanf("%s", com);
		if (!strcmp("push", com)) {
			int i = 0;
			scanf("%d", &i);
			q.push_back(i);
		}
		else if (!strcmp("pop", com)) {
			if (q.empty())
				printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop_front();
			}
		}
		else if (!strcmp("front", com)) {
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		else if (!strcmp("back", com)) {
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.back());
		}
		else if (!strcmp("size", com)) {
			printf("%d\n", q.size());
		}
		else if (!strcmp("empty", com)) {
			printf("%d\n", q.empty());
		}

	}
	return 0;
}
