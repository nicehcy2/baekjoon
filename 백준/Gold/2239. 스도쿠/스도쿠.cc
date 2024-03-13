#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int arr[9][9];
vector<pair<int, int>> empt;

void Input() {

	for (int i = 0; i < 9; i++) {

		string str; cin >> str;
		for (int j = 0; j < 9; j++) {

			arr[i][j] = str[j] - '0';

			if (!arr[i][j]) empt.push_back({i, j});
		}
	}
}

bool check() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (!arr[i][j]) return false;
		}
	}

	return true;
}

bool isPossible(int y, int x, int k) {

	for (int row = 0; row < 9; row++) {
		if (arr[y][row] == k) {
			return false;
		}
	}

	for (int col = 0; col < 9; col++) {
		if (arr[col][x] == k) {
			return false;
		}
	}

	for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++) {
		for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {

			if (arr[i][j] == k) {
				return false;
			}
		}
	}

	return true;
}

void dfs(int idx) {

	if (idx == empt.size()) {

		if (!check()) {
			return;
		}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {

				cout << arr[i][j];
			}
			cout << '\n';
		}

		exit(0);
	}

	int y = empt[idx].first;
	int x = empt[idx].second;

	for (int k = 1; k <= 9; k++) {

		if (isPossible(y, x, k)) {
			arr[y][x] = k;
			dfs(idx + 1);
		}
	}
	arr[y][x] = 0;
}

void Solution() {

	dfs(0);
}

int main() {
	
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}