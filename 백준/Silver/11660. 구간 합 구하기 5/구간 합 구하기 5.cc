#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int n, m;
int arr[1025][1025];

void InitAndInput() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (i > 1) {
				arr[i][j] = arr[i][j] + arr[i - 1][j];
			}
		}
	}
}

void Solution() {
	while (true) {
		if (m == 0) break;

		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		int sum = 0;

		for (int i = x1; i <= x2; i++) {
			sum += (arr[y2][i] - arr[y1 - 1][i]);
		}

		cout << sum << '\n';

		m--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InitAndInput();
	Solution();

	return 0;
}