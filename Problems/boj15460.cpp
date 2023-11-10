//Problem Number : 15460
//Problem Title : My Cow Ate My Homework
//Problem Link : https://www.acmicpc.net/problem/15460

#include <iostream>
#include <vector>

using namespace std;

int s[100001];
int m[100001];
vector<int> v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, input;
    cin >> n;
    cin >> s[0];
    for (int i = 1; i < n; i++) {
        cin >> input;
        s[i] = s[i - 1] + input;
    }

    int mini = 1234567890;
    for (int i = n - 1; i > 0; i--) {
        if (mini > s[i] - s[i - 1]) {
            mini = s[i] - s[i - 1];
        }
        m[i] = mini;
    }
    if (mini > s[0]) {
        mini = s[0];
    }
    m[0] = mini;

    double maxScore = -1;

    for (int i = 0; i < n - 2; i++) {
        double score = (double)(s[n - 1] - s[i] - m[i + 1]) / (n - i - 2);

        if (score > maxScore) {
            maxScore = score;
            v.clear();
            v.push_back(i + 1);
        }
        else if (score == maxScore) {
            v.push_back(i + 1);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}