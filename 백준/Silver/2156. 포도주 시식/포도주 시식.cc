#include <iostream>

using namespace std;

int N, ans;
int arr[10001], dp[10001];

void Input() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void Solution() {

	dp[1] = arr[1]; dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; i++) {

		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}

	for (int i = 1; i <= N; i++) {

		ans = max(dp[i], ans);
	}

	cout << ans << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}