#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n;
char word;
vector<string> v;
map<string, bool> player;

void Input() {
	cin >> n >> word;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
}

void Solution() {
	int cnt = 0, user = 1, answer = 0;

	if (word == 'Y') {
		cnt = 2;
	}
	else if (word == 'F') {
		cnt = 3;
	}
	else if (word == 'O') {
		cnt = 4;
	}

	for (int i = 0; i < n; i++) {
		if (player[v[i]] == false) {
			user++;
			player[v[i]] = true;
		}

		if (user == cnt) {
			user = 1;
			answer++;
		}
	}

	cout << answer << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}