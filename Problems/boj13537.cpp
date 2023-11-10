//Problem Number : 13537
//Problem Title : None
//Problem Link : https://www.acmicpc.net/problem/13537

#include <iostream>
#include <algorithm>

#define MOD (int)1e8

using namespace std;

char cmd[4444];
char str[4444];
int m, c, n;

pair<int, int> checkCmd(int mm, int cc, int nn)
{
    pair<int, int> ret = { 0,0 };
    int pm = mm, pc = cc;
    int iter = 0;

    while (pc < c) {
        if (cmd[pc] == '+' || cmd[pc] == '>') {
            pm++;
        }
        else if (cmd[pc] == '-' || cmd[pc] == '<') {
            pm--;
        }
        else if (cmd[pc] == '[') {
            if (pm == 0) {
                while (cmd[pc] == ']') {
                    pc++;
                }
            }
            else {
                ret = checkCmd(pm, pc + 1, nn);
            }
        }

        if (pm == m) {
            pm = 0;
        }
        else if (pm < 0) {
            pm = m - 1;
        }
        pc++;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int TC;

    cin >> TC;

    while (TC--) {
        int m, c, n;

        cin >> m >> c >> n;
        cin >> cmd;
        cin >> str;

        pair<int, int> ans = checkCmd(0, 0, 0);
        if (ans.first == ans.second) {
            cout << "Terminates\n";
        }
        else {
            cout << "loop " << ans.first << ' ' << ans.second;
        }
    }

    return 0;
}