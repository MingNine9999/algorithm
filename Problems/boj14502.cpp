//Problem Number : 14502
//Problem Title : 연구소
//Problem Link : https://www.acmicpc.net/problem/14502

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int goX[4] = {1, 0, -1, 0};
int goY[4] = {0, 1, 0, -1};
int in[11][11];
int check[11][11];
int N, M;
int staticInfested;
int minInfested;
int wallCount;
int checkValue;

int infested;

void dfs(int r, int c) 
{
    if (r > N || infested > minInfested) {
        return;
    }
    if (c > M) {
        return dfs(r + 1, 1);
    }
    if (in[r][c] != 2 && in[r][c] != checkValue) {
        return dfs(r, c + 1);
    }

    for (int d = 0; d < 4; d++) {
        int rr = r + goX[d];
        int cc = c + goY[d];
        if (in[rr][cc] <= 0 && check[rr][cc] != checkValue) {
            in[rr][cc] = checkValue;
            check[rr][cc] = checkValue;
            infested++;
            dfs(rr, cc);
        }
    }

    return dfs(r, c + 1);
}

void setWall(int r, int c, int wall)
{
    if (wall == 3) {
        checkValue--;    
        infested = 0;
        dfs(1, 1);

        if (minInfested > infested) {
            minInfested = infested;
        }

        return;
    }
    if (r > N) {
        return;
    }
    if (c > M) {
        setWall(r + 1, 1, wall);
        return;
    }
    if (in[r][c] > 0) {
        setWall(r, c + 1, wall);
        return;
    }

    in[r][c] = 1;
    setWall(r, c + 1, wall + 1);
    in[r][c] = 0;
    setWall(r, c + 1, wall);
    
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> in[i][j];

            if (in[i][j] == 1) {
                wallCount++;
            } else {
                if (in[i][j] == 2) {
                    staticInfested++;
                }
                minInfested++;
            }
        }
    }

    for (int i = 0; i <= N + 1; i++) {
        in[i][0] = 1;
        in[i][M + 1] = 1; 


    }
    for (int i = 0; i <= M + 1; i++) {
        in[0][i] = 1;
        in[N + 1][i] = 1;
    }

    setWall(1, 1, 0);

    cout << N * M - (minInfested + staticInfested + wallCount + 3);

    return 0;
}
