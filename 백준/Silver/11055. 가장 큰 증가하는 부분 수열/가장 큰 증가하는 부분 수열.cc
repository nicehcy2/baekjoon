#include <iostream>
#include <vector>
#include <algorithm>

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
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) {
				dp[i] = dp[j] + arr[i];
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