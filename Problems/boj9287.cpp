//Problem Number : 9287
//Problem Title : Jenga
//Problem Link : https://www.acmicpc.net/problem/9287

#include <stdio.h>

int main() {
	int t, c = 0;
	scanf("%d", &t);
	while (t--) {
		char jenga[22][4] = { 0 };
		int h, fallen = 0;
		c++;
		scanf("%d", &h);
		for (int i = 0; i < h; i++) {
			scanf("%s", jenga[i]);
		}
		for (int i = 0; i < h; i++)
			if (jenga[i][1] == '0') 
				if (jenga[i][0] == '0' || jenga[i][2] == '0')
					fallen++;
		
		if (fallen)
			printf("Case %d: Fallen\n", c);
		else
			printf("Case %d: Standing\n", c);
	}
	return 0;
}