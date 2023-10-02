#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2100000000

using namespace std;

unsigned n, newScore, p;
vector<unsigned> arr;

void Input() {
	cin >> n >> newScore >> p;
	for (unsigned i = 0; i < n; i++) {
		int score;
		cin >> score;
		arr.push_back(score);
	}
}

void Solution() {
	int rank = 1, cnt = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > newScore) {
			rank++;
		}
		else if (arr[i] == newScore) {

		}
		else {
			break;
		}
		cnt++;
	}

	if (cnt ==  p) {
		cout << "-1\n";
		return;
	}
	if (n == 0) {
		cout << "1\n";
		return;
	}

	cout << rank << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}