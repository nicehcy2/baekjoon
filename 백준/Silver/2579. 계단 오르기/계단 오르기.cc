#include <iostream>

using namespace std;

int N;
int dp[1010], arr[1010];

void Input() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void Solution() {

	dp[0] = 0, dp[1] = arr[1], dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	}

	cout << dp[N] << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}