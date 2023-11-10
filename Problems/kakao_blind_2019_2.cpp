// KAKAO BLIND RECRUITMENT 2019
// 블록게임

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
queue<int> blockX[55];

const int goY[][6] = { { 0,0,0,1,1,1 },{ 0,0,0,1,1,1 },{ 0,0,0,1,1,1 },{ 0,0,1,1,2,2 },{ 0,0,1,1,2,2 } };
const int goX[][6] = { { -2,-1,0,-2,-1,0 },{ 2,1,0,2,1,0 },{ -1,0,1,-1,0,1 },{ -1,0,-1,0,-1,0 },{ 1,0,1,0,1,0 } };

int check(vector<vector<int>> board, int y, int x) {
	int ret = -1;

	int checkB = 0;
	int checkZ = 0;
	for (int i = 0; i < 5; i++) {
		checkB = 0;
		checkZ = 0;
		for (int j = 0; j < 6; j++) {
			int yy = y + goY[i][j];
			int xx = x + goX[i][j];

			if (yy < 0 || yy >= board.size() || xx < 0 || xx >= board.size() || (blockX[xx].empty() || blockX[xx].front() != board[y][x])) break;

			if (board[yy][xx] == 0) {
				checkZ++;
			}
			else if (board[yy][xx] == board[y][x]) {
				checkB++;
			}
			else {
				break;
			}

			if (j == 3 && checkZ < 2) checkZ = -1234567890;
		}

		if (checkB == 4 && checkZ == 2) {
			for (int j = 0; j < 3; j++) {
				int xx = x + goX[i][j];

				if (!blockX[xx].empty() && blockX[xx].front() == board[y][x]) {
					blockX[xx].pop();
				}
			}

			ret = i;
			break;
		}
		else if (checkB == 4) {
			for (int j = 0; j < 3; j++) {
				int xx = x + goX[i][j];

				blockX[xx].push(board[y][x]);
			}

			if (checkZ < 0) {
				ret = -1234567890;
			}
		}
	}

	return ret;
}

int solution(vector<vector<int>> board) {
	int answer = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] != 0) {
				int c = check(board, i, j);
				
				if (c == -1) {
					q.push({ i,j });
				}
				else if (c < -1) {
					continue;
				}
				else {
					for (int k = 0; k < 6; k++) {
						int y = i + goY[c][k];
						int x = j + goX[c][k];

						board[y][x] = 0;
					}
					answer++;
				}
			}
		}
	}

	int qsize = 0;
	while (qsize != q.size()) {
		qsize = q.size();
		if (qsize == 0) {
			break;
		}

		for (int i = 0; i < qsize; i++) {
			pair<int, int> f = q.front(); q.pop();
			
			int c = check(board, f.first, f.second);

			if (c == -1) {
				q.push(f);
			}
			else if (c < -1) {
				continue;
			}
			else {
				for (int k = 0; k < 6; k++) {
					int y = f.first + goY[c][k];
					int x = f.second + goX[c][k];

					board[y][x] = 0;
				}
				answer++;
			}
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	vector<vector<int>> v;

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		v[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	cout << solution(v);

	return 0;
}

/*
10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 4 0 0 0
0 0 0 0 0 4 4 0 0 0
0 0 0 0 3 0 4 0 0 0
0 0 0 2 3 0 0 0 5 5
1 2 2 2 3 3 0 0 0 5
1 1 1 0 0 0 0 0 0 5

5
1 0 0 0 0
1 0 2 2 0
1 1 3 2 0
3 3 3 2 1
0 0 1 1 1
*/