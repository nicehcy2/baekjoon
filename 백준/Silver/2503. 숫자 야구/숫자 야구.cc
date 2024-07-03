#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int t;
map<int, bool> key;

void Input() {

	cin >> t;
}

void Solution() {

	string candicate;
	int strike, ball;

	for (int i = 100; i <= 999; i++) {
		key[i] = true;
	}

	while (t--) {

		cin >> candicate >> strike >> ball;

		for (int i = 100; i <= 999; i++) {

			string num = to_string(i);
			int s = 0, b = 0;

			for (int j = 0; j < 3; j++) {
				if (candicate[j] == num[j]) {
					s++;
				}
			}

			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if ((candicate[j] == num[k]) && (j != k)) {
						b++;
					}
				}
			}

			if ((s != strike) || (b != ball)) {
				key[i] = false;
			}
		}
	}

	int cnt = 0;
	for (int i = 100; i <= 999; i++) {
		if (key[i] == true) {

			string value = to_string(i);
			bool uniq = false;
			for (int j = 0; j < 3; j++) {
				for (int k = j + 1; k < 3; k++) {
					if (value[j] == value[k]) {
						uniq = true;
					}
				}
			}

			for (int j = 0; j < 3; j++) {
				if (value[j] == '0') uniq = true;
			}

			if (uniq == false) {
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}