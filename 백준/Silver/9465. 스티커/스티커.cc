#include <iostream>
#include <cstring>

using namespace std;

int T, N;
int arr[2][100001], dp[2][100001];

void Input() {
}

void Solution() {

	cin >> T;

	while (T--) {

		cin >> N;

		memset(dp, 0, sizeof(dp));
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		// Soltuion
		dp[0][0] = arr[0][0], dp[1][0] = arr[1][0];
		dp[0][1] = dp[1][0] + arr[0][1], dp[1][1] = dp[0][0] + arr[1][1];

		for (int i = 2; i < N; i++) {
			dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + arr[0][i];
			dp[0][i] = max(dp[0][i], dp[1][i - 1] + arr[0][i]);

			dp[1][i] = max(dp[0][i - 2], dp[1][i - 2]) + arr[1][i];
			dp[1][i] = max(dp[1][i], dp[0][i - 1] + arr[1][i]);
		}

		int ans = max(dp[0][N - 1], dp[1][N - 1]);

		cout << ans << '\n';
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