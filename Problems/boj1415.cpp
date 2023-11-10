//Problem Number : 1415
//Problem Title : 사탕
//Problem Link : https://www.acmicpc.net/problem/1415

#include <iostream>
#include <set>

using namespace std;

set<int> s;
set<int> make;
int price[10001];
long long sack[500002];
int prime[500002];

void eratos(int n)
{
	for (int i = 2; i * i <= n; i++) {
		if (prime[i] == 0){
			for (int j = 2; i * j <= n; j++) {
				prime[i * j] = 1;
			}
		}
	}

	prime[0] = prime[1] = 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int input;
	long long maxPrice = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		price[input]++;
		s.insert(input);

		if (input > maxPrice) {
			maxPrice = input;
		}
	}

	if (*(s.begin()) == 0) {
		s.erase(s.begin());
	}

	sack[0] = 1;

	long long last = 0;
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		long long tmp = last + *iter * price[*iter];
		for (int j = last; j >= 0; j--) {
			for (int k = 1; k <= price[*iter]; k++) {
				long long tmp2 = j + *iter * k;
				sack[tmp2] += sack[j];
				make.insert(tmp2);
			}
		}
		last = tmp;
	}

	eratos(last);

	long long ans = 0;

	for (set<int>::iterator iter = make.begin(); iter != make.end(); iter++) {
		if (prime[*iter] == 0) {
			ans += sack[*iter];
		}
	}

	ans *= price[0] + 1;
	cout << ans;

	return 0;
}
