#include <iostream>
#include <string>

using namespace std;

string str;

void Input() {
	
	cin >> str;
}

void Solution() {

	string tmp = "";
	int ans = 0;
	bool isMinus = false;
	str += "+";

	for (int i = 0; i < str.size(); i++) {

		if (str[i] == '+' || str[i] == '-') {
			if (isMinus) {
				ans -= stoi(tmp);
			}
			else {
				ans += stoi(tmp);
			}
			tmp = "";
		}
		else {
			tmp += str[i];
		}

		if (str[i] == '-') {
			isMinus = true;
		}
	}

	cout << ans << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}