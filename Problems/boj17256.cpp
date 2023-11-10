//Problem Number : 17256
//Problem Title : 달달함이 넘쳐흘러
//Problem Link : https://www.acmicpc.net/problem/17256

#include <iostream>

using namespace std;

struct cake {
	int x, y, z;
};

cake reverse(cake a, cake c)
{
	return { c.x - a.z, c.y / a.y, c.z - a.x };
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cake a, b, c;

	cin >> a.x >> a.y >> a.z;
	cin >> c.x >> c.y >> c.z;

	b = reverse(a, c);

	cout << b.x << ' ' << b.y << ' ' << b.z;

	return 0;
}