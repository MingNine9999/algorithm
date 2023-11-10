//Problem Number : ??
//Problem Title : 문자열 압축
//Problem Link : https://programmers.co.kr/learn/courses/30/lessons/60057 

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int solution(string s)
{
    int answer = s.size();

    for (int n = 1; n <= s.size() / 2; n++) {
        int tmp = s.size();
        int check = 0;
        for (int i = 0; i + n < s.size(); i += n) {
            if (strncmp(s.c_str() + i, s.c_str() + i + n, n) == 0) {
                if (check) {
                    tmp -= n;
                    check++;
                    if (check == 10) {
                        tmp++;
                    }
                    else if (check == 100) {
                        tmp++;
                    }
                    else if (check == 1000) {
                        tmp++;
                    }
                }
                else {
                    check = 2;
                    tmp -= n;
                    tmp++;
                }
            }
            else {
                check = 0;
            }
        }
        answer = min(answer, tmp);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin >> s;

    cout << solution(s);

    return 0;
}
