//Problem Number : 10799
//Problem Title : 쇠막대기
//Problem Link : https://www.acmicpc.net/problem/10799

#include <iostream>
#include <stack>

using namespace std;

stack<char> stick;
char par[100001];

int main() {
	cin >> par;

	int ans = 0;
	for (int i = 0; par[i] != 0; i++) {
		if (par[i] == '(') {
			if (par[i + 1] == '(') {
				stick.push(par[i]);
			}
			else {
				ans += stick.size();
				i++;
			}
		}
		else {
			stick.pop();
			ans++;
		}
	}

	cout << ans;

	return 0;
}