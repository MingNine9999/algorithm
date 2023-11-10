//Problem Number : 17419
//Problem Title : 비트가 넘쳐흘러
//Problem Link : https://www.acmicpc.net/problem/17419

#include <cstdio>

using namespace std;

char a[1111111];

int main(void)
{
	int n = 0;

	scanf("%d", &n);
	scanf("%s", a);

	n = 0;
	for (int i = 0; a[i] != 0; i++) {
		if (a[i] == '1') {
			n++;
		}
	}

	printf("%d\n", n);

	return 0;
}
