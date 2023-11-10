//Problem Number : 2250
//Problem Title : 트리의 높이와 너비
//Problem Link : https://www.acmicpc.net/problem/2250

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
	int par;
	int left;
	int right;
	int level;
	int index;
} tree;

int srt[10002];
tree t[10002];
int visit[10002];
vector<int> lvGroup[10002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	int a;
	for(int i = 0; i < n; i++) {
		cin >> a;
		cin >> t[a].left >> t[a].right;
		if(t[a].left != -1) {
			t[t[a].left].par = a;
			srt[t[a].left]++;
		}
		if(t[a].right != -1) {
			t[t[a].right].par = a;
			srt[t[a].right]++;
		}
	}

	int root;
	for(int i = 1; i <= n; i++) {
		if(srt[i] == 0) {
			root = i;
			break;
		}
	}
	int lv = t[root].level = 1;
	int maxLv;
	
	queue<int> q;
	q.push(root);
	lvGroup[1].push_back(root);
	while(1) {
		int s = q.size();
		if(s == 0) {
			maxLv = lv;
		break;
		}

		lv++;
		for(int i = 0; i < s; i++) {
			int tmpL = t[q.front()].left;
			int tmpR = t[q.front()].right;
			if(tmpL != -1) {
				t[tmpL].level = lv;
				lvGroup[lv].push_back(tmpL);
				q.push(tmpL);
			}
			if(tmpR != -1) {
				t[tmpR].level = lv;
				lvGroup[lv].push_back(tmpR);
				q.push(tmpR);
			}
			q.pop();
		}
	}

	stack<int> stk;
	int i = 1;
	stk.push(root);
	while(i <= n) {
		int Lchild = t[stk.top()].left;
		while(Lchild != -1 && visit[Lchild] != 1) {
			stk.push(Lchild);
			visit[Lchild] = 1;
			Lchild = t[stk.top()].left;
		}
			
		t[stk.top()].index = i++;
		int Rchild = t[stk.top()].right;
		stk.pop();
		if(Rchild != -1 && visit[Rchild] != 1) {
			stk.push(Rchild);
			visit[Rchild] = 1;
		}
	}

	int maxBreadth = 0;
	int maxBreadthLv = 0;
	for(int i = 1; i <= maxLv; i++) {
		int mL = 1234567890;
		int mR = 0;
		for(int j = 0; j < lvGroup[i].size(); j++) {
			int tmpI = t[lvGroup[i][j]].index;
			if(tmpI < mL) {
				mL = tmpI;
			}
			if(tmpI > mR) {
				mR = tmpI;
			}
		}
		int bth = mR - mL + 1;
		if(maxBreadth < bth) {
			maxBreadth = bth;
			maxBreadthLv = i;
		}
	}

	cout << maxBreadthLv << " " << maxBreadth;
	
	return 0;
}
