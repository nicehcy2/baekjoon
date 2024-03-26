#include <iostream>
#include <cstring>

using namespace std;

#define INF 1000000000

int N, K, ans = INF;
int dp[21];
pair<int, int> arr[21];

void Input() {
	
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	cin >> K;

	arr[0].first = INF, arr[0].second = INF;
}

void Solution() {

	for (int i = 2; i <= N; i++) {
		dp[i] = min(dp[i - 1] + arr[i - 1].first, dp[i - 2] + arr[i - 2].second);
	}
	ans = dp[N];
	
	// super jump를 하는 경우
	for (int j = 1; j <= N - 3; j++) {
		memset(dp, 0, sizeof(dp));

		for (int i = 2; i <= N; i++) {
			if (i == j + 3) dp[i] = dp[i - 3] + K;
			else dp[i] = min(dp[i - 1] + arr[i - 1].first, dp[i - 2] + arr[i - 2].second);
		}
		ans = min(ans, dp[N]);
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