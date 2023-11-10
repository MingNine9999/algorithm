//Problem Number : 16637
//Problem Title : 괄호 추가하기 
//Problem Link : https://www.acmicpc.net/problem/16637

#include <iostream>
#include <algorithm>

using namespace std;

int n;
char str[22];
int num[22];
char math[22];
int check[22];

int cal(int a, int b, char c)
{
	switch (c) {
		case '+' :
			return a + b;
		case '-' :
			return a - b;
		case '*' :
			return a * b;
		default :
			return a;
	}
}

int dfs(int v)
{
	int ret = num[0];
	int lv, rv;

	if (v != 0) {
		lv = num[v - 1];
		rv = num[v];
		num[v - 1] = num[v] = cal(lv, rv, math[v]);
	}

	for (int i = 1; i < n / 2 + 1; i++) {
		if (check[i] == 0) {
			ret = cal(ret, num[i], math[i]);
		}
	}

	for (int i = v + 2; i < n / 2 + 1; i++) {
		if (check[i]) continue;

		check[i] = 1;
		ret = max(ret, dfs(i));
		check[i] = 0;
	}

	if (v != 0) {
		num[v - 1] = lv;
		num[v] = rv;
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	cin >> str;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			num[i / 2] = (int)(str[i] - '0');
		}
		else {
			math[i / 2 + 1] = str[i];
		}
	}

	cout << dfs(0);

	return 0;
}