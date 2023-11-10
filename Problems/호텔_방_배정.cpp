// Problem Number : ??
// Problem Title : 호텔 방 배정
// Problem Link : https://programmers.co.kr/learn/courses/30/lessons/64063

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> par;

long long find(long long a)
{
    if (par[a] == 0) {
        return a;
    }
    
    return par[a] = find(par[a]);
}

long long merge(long long a, long long b)
{
    if (a > b) {
        return merge(b, a);
    }

    a = find(a);
    b = find(b);
    
    par[a] = par[b] = b + 1;
    return b;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (int i = 0; i < room_number.size(); i++) {
        long long r = room_number[i];
        long long f = find(r);
        if (f == r) {
            par[r] = r + 1;
        }
        else {
            f = merge(r, f);
        }

        answer.push_back(f);
    }

    return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k;
    int n;
    vector<long long> room;
    
    
    cin >> k;
    cin >> n;
    room.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> room[i];
    }

    vector<long long> ans = solution(k, room);
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

	return 0;
}