#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#pragma warning disable:4996

using namespace std;

int arr[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, cnt = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		while (true) {
			if (arr[i] <= k) {
				k -= arr[i];
				cnt++;
			}
			else {
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}	