//Problem Number : 10757
//Problem Title : 큰 수 A+B
//Problem Link : https://www.acmicpc.net/problem/10757

#include <iostream>
#include <cstring>

using namespace std;

char in1[11111], in2[11111];
char out[11111];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> in1;
    cin >> in2;

    int len1 = strlen(in1) - 1;
    int len2 = strlen(in2) - 1;
    int size = len1 > len2 ? len1 : len2;
    int carry = 0;

    for (int i = size + 1; i >= 0; i--) {
        int a = 0, b = 0;

        if (len1 >= 0) {
            a = in1[len1] - '0';
            len1--;
        }
        if (len2 >= 0) {
            b = in2[len2] - '0';
            len2--;
        }

        out[i] = (a + b + carry) % 10 + '0';
        carry = (a + b + carry) / 10;
    }

    if (out[0] == '0') {
        cout << out + 1 << "\n";
    } else {
        cout << out << "\n";
    }

    return 0;
}
