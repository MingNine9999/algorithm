//Problem Number : 2504
//Problem Title : 괄호의 값
//Problem Link : https://www.acmicpc.net/problem/2504

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

char str[33];
int idx = -1;

int recur(int bc)
{
    int ret = 0;

    while (str[++idx] != 0) {
        if (str[idx] == '(') {
            ret += recur(2);
        }
        else if (str[idx] == '[') {
            ret += recur(3);
        }
        else if (str[idx] == ')') {
            if (bc != 2) {
                return -1234567890;
            }
            if (ret == 0) {
                ret = 1;
            }

            return ret *= 2;
        }
        else if (str[idx] == ']') {
            if (bc != 3) {
                return -1234567890;
            }
            if (ret == 0) {
                ret = 1;
            }

            return ret *= 3;
        }

        if (ret < 0) {
            return -1234567890;
        }
    }

    if (bc == 1) {
        return ret;
    }
    else {
        return -1234567890;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;

    int ans = recur(1);

    cout << (ans > 0 ? ans : 0);

    return 0;
}