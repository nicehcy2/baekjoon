#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
vector<string> v;

void Input() {
	cin >> str;

	string tmp = "";
	int cnt = 0;

	for (int i = 0; i < str.size(); i++) {

		tmp = "";
		for (int j = i; j < str.size(); j++) {
			tmp += str[j];
		}
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (auto vec : v) {
		cout << vec << '\n';
	}
}

void Solution() {

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}