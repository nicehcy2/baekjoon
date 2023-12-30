#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

int T, N;

void Solution(vector<string>& str) {
	sort(str.begin(), str.end());
	unordered_set<string> hash_set;
	bool flag = false;

	for (int i = 0; i < str.size(); i++) {
		string arr = "";

		for (int j = 0; j < str[i].length() - 1; j++) {
			arr += str[i][j];
			// unoredered_set에서 find 함수를 사용하여 arr를 찾고 있으면 해당 요소를 가르키는 반복자를 반환,
			// 없으면 hash_set.end()를 반환한다.
			if (hash_set.find(arr) != hash_set.end()) {
				flag = true;
				cout << "NO" << '\n';
				return;
			}
		}
		if (flag) return;
		hash_set.insert(str[i]);
	}

	cout << "YES\n";
	return;
}

void Input() {
	cin >> T;

	while (T--) {
		cin >> N;

		vector<string> s;
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			s.push_back(str);
		}
		Solution(s);
	}
}

int main() {
	Input();
	//Solution();

	return 0;
}