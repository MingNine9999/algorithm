//Problem Number : 10864
//Problem Title : 친구
//Problem Link : https://www.acmicpc.net/problem/10864

#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n,m;
	scanf("%d%d", &n,&m);
	vector<int> v;
	v.resize(n+1);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a]++;
		v[b]++;
	}
	for (int i = 1; i < v.size(); i++)
		printf("%d\n", v[i]);
	return 0;
}