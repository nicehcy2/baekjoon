#include <iostream>

using namespace std;

int N;
pair<int, int> arr[1500002];
long long dp[1500002];

void Input() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
}

void Solution() {

	for (int i = N; i > 0; i--) {

		if (arr[i].first + i <= N + 1) {
			dp[i] = arr[i].second + dp[i + arr[i].first];
			dp[i] = max(dp[i], dp[i + 1]);
		}
		else {
			dp[i] = 0;
			dp[i] = max(dp[i], dp[i + 1]);
		}
	}

	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp[i]);
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