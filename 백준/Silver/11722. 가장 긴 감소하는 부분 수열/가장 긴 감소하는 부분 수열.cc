#include <iostream>

using namespace std;

int n;
int arr[1001], dp[1001];

void Input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void Solution() {
	int max = -1;

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] > arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i]) {
			max = dp[i];
		}
	}

	cout << max << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}