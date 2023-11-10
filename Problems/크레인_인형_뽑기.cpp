//Problem Number : ??
//Problem Title : 크레인 인형뽑기 게임
//Problem Link : https://programmers.co.kr/learn/courses/30/lessons/64061

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > board;
vector<int> moves;

int solution()
{
	int answer = 0;
	vector<int> top;
	stack<int> s;
	   
	top.resize(board[0].size());
	for (int i = 0; i < top.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j][i] != 0) {
				top[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < moves.size(); i++) {
		int x = moves[i] - 1;
		int y = top[x];

		if (y == board.size()) {
			continue;
		}

		if (!s.empty() && s.top() == board[y][x]) {
			s.pop();
			answer += 2;
		}
		else {
			s.push(board[y][x]);
		}

		top[x]++;
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	
	cin >> n >> m;

	board.resize(n);
	for (int i = 0; i < n; i++) {
		board[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int r;

	cin >> r;
	
	moves.resize(r);
	for (int i = 0; i < r; i++) {
		cin >> moves[i];
	}

	cout << solution();

	return 0;
}

/* 
5 5
0 0 0 0 0
0 0 1 0 3
0 2 5 0 1
4 2 4 4 2
3 5 1 3 1
8
*/