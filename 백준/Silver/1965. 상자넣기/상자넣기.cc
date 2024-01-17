#include <iostream>

using namespace std;

int N;
int arr[1001], dp[1001];

void Solution() {
	dp[0] = 1;

	for (int i = 1; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int m = 0;
	for (int i = 0; i < N; i++) {
		m = max(m, dp[i]);
	}

	cout << m << '\n';
}

void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int main() {
	Input();
	Solution();

	return 0;
}