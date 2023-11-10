//Problem Number : 4806
//Problem Title : 줄 세기
//Problem Link : https://www.acmicpc.net/problem/4806

#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cnt = 0;
	char buf[111];
	while (!cin.eof())
	{
		cin.getline(buf, 109);
		cnt++;
	}

	cout << cnt - 1;
	
	return 0;
}