#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#define NOTNUM '0'
#define MAXRAND 10

using namespace std;

int n;
string s[11];
pair<int, string> str[11];
pair<int, char> alpha[26];
int alToNum[26];
int ran[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		str[i] = { s[i].size(), s[i] };
	}
}

string convertStr(string s, int max) {
	string temp;

	if (s.size() < max) {
		int diff = max - s.size();

		for (int i = 0; i < diff; i++) {
			temp += '0';
		}
	}

	return temp + s;
}

int stringToInt(string s) {
	int num = 0;

	for (int i = 0; i < s.size(); i++) {
		num += alToNum[s[i] - 'A'] * pow(10, s.size() - i - 1);
	}

	return num;
}

void Solution() {
	int max = 0, cnt = 0, sum = 0;

	sort(str, str + n, greater<>());
	max = str[0].first;

	for (int i = 0; i < n; i++) {
		str[i].second = convertStr(str[i].second, max);
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < n; j++) {
			if (str[j].second[i] != NOTNUM) {
				alpha[str[j].second[i] - 'A'].first += pow(10, max - i - 1);
				alpha[str[j].second[i] - 'A'].second = str[j].second[i];
			}
		}
	}

	sort(alpha, alpha + 26, greater<>());


	for (int i = 0; i < MAXRAND; i++) {
		if (alpha[i].first == 0) {
			break;
		}

		alToNum[alpha[i].second - 'A'] = ran[cnt++];
	}


	for (int i = 0; i < n; i++) {
		sum += stringToInt(str[i].second);
	}

	cout << sum << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}