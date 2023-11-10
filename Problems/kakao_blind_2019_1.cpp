// KAKAO 2019 BLIND RECRUITMENT
// ¸ÅÄª Á¡¼ö

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int solution(string word, vector<string> pages) {
	int answer = 0;
	vector<string> url;
	vector<string> link[22];
	vector<double> base;
	map<string, double> score;

	for (int i = 0; i < word.size(); i++) {
		if (isupper(word[i])) {
			word[i] = tolower(word[i]);
		}
	}

	for (int i = 0; i < pages.size(); i++) {
		int check = 0;
		vector<string> tmp;
		base.push_back(0);

		int k = 0;
		for (int j = 0; j < pages[i].size(); j++) {
			tmp.push_back("");
			
			if (j != 0 && pages[i][j - 1] == '<') {
				tmp[k] += pages[i][j - 1];
			}

			while (j < pages[i].size() && pages[i][j] != '<') {
				while (tmp[k].compare("") == 0 && pages[i][j] == ' ') {
					j++;
				}
				if (pages[i][j] == '>') {
					tmp[k] += pages[i][j];
					break;
				}
				tmp[k] += pages[i][j++];
			}
			
			if (tmp[k].size() > 5 && tmp[k].substr(1, 4).compare("meta") == 0) {
				string cur = "";
				int idx = tmp[k].find("content", 7);

				if (idx != -1) {
					idx += 7;
					while (tmp[k][++idx] != '\"');
					while (tmp[k][++idx] != '\"') {
						cur += tmp[k][idx];
					}

					url.push_back(cur);
					score[cur] = 0;
				}
			}
			else if (tmp[k][0] != '<') {
				string body = tmp[k];
				for (int idx = 0; idx < body.size(); idx++) {
					if (isupper(body[idx])) {
						body[idx] = tolower(body[idx]);
					}
				}

				for (int idx = 0; idx + word.size() <= body.size(); idx++) {
					if (body.compare(idx, word.size(), word) == 0) {
						if ((idx == 0 || ('a' > body[idx - 1] && body[idx - 1] < 'z')) && (idx + word.size() == body.size() || ('a' > body[idx + word.size()] && body[idx + word.size()]))) {
							base[i]++;
						}
					}
				}
			}
			else if (tmp[k].size() > 7 && tmp[k].substr(1, 6).compare("a href") == 0) {
				int idx = 0;
				string l = "";

				while (tmp[k][++idx] != '\"');
				while (tmp[k][++idx] != '\"') {
					l += tmp[k][idx];
				}

				link[i].push_back(l);
			}
			k++;
		}	
	}

	for (int i = 0; i < url.size(); i++) {
		double link_score = base[i] / link[i].size();
		for (int j = 0; j < link[i].size(); j++) {
			score[link[i][j]] += link_score;
		}
	}

	for (int i = 1; i < url.size(); i++) {
		if (base[answer] + score[url[answer]] < base[i] + score[url[i]]) {
			answer = i;
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string word;
	string input;
	vector<string> pages;

	cin >> word;

	pages.push_back("<html lang = \"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>");
	pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>");
	pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>");

	cout << solution(word, pages);

	return 0;
}