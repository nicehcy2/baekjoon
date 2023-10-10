#include <iostream>
#include <vector>;
#include <algorithm>

#define INF 2100000000

using namespace std;

int n, k, cntK = 0;
bool arr[1001];

void Input() {
	cin >> n >> k;
}

void Solution() {
	int count = n - 2 + 1, idx = 1;

	for (int i = 2; i <= n; i++) {
		arr[i] = true;
	}

	while (count) {
		int min = INF, idx = 1;

		for (int i = 2; i <= n; i++) {
			if (min > i && arr[i] == true) {
				min = i;
			}
		}

		while (true) {
			if (idx * min > n) {
				break;
			}

			if (arr[min * idx]) {
				arr[min * idx] = false;
				cntK++;

				if (cntK == k) {
					cout << min * (idx) << '\n';
					return;
				}
			}
			idx++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}