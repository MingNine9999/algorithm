//Problem Number : 16769
//Problem Title : Mixing Milk
//Problem Link : https://www.acmicpc.net/problem/16769

#include <iostream>

using namespace std;

int bucketMax[3];
int bucket[3];

void move(int from, int to)
{
    if (bucket[from] + bucket[to] > bucketMax[to]) {
        bucket[from] += bucket[to] - bucketMax[to];
        bucket[to] = bucketMax[to];
    }
    else {
        bucket[to] += bucket[from];
        bucket[from] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++) {
        cin >> bucketMax[i] >> bucket[i];
    }

    move(0, 1);
    move(1, 2);
    move(2, 0);
    move(0, 1);

    for (int i = 0; i < 3; i++) {
        cout << bucket[i] << '\n';
    }

    return 0;
}