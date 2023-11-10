//Problem Number : 1969
//Problem Title : DNA
//Problem Link : https://www.acmicpc.net/problem/1969

#include <iostream>
#include <string>


using namespace std;


string dna[1001];
char alpha[4] = { 'A','C','G','T' };
int value[4];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> dna[i];
	}
	string ans;
	int hamdis = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			value[j] = 0;
		}
		

		for (int j = 0; j < n; j++) {
			for (int l = 0; l < 4; l++) {
				if (dna[j][i] == alpha[l]) {
					value[l]++;
					break;
				}
			}
		}

		int max = 0;
		for (int j = 1; j < 4; j++) {
			if (value[j] > value[max]) {
				max = j;
			}			
		}
		hamdis += n - value[max];

		ans.push_back(alpha[max]);
	}

	cout << ans << "\n" << hamdis;

	return 0;
}