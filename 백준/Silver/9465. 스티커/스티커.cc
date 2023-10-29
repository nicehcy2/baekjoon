#include <iostream>

using namespace std;

int T, n;
int dp[2][100001];
int arr[2][100001];

int mmax(int a, int b) {
	return (a > b) ? a : b;
}

int Solution() {
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[0][1] = arr[0][1];
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		//dp[0][i] = mmax(dp[1][i - 1] + arr[0][i], dp[0][i - 2] + arr[0][i]);
		//dp[1][i] = mmax(dp[0][i - 1] + arr[1][i], dp[1][i - 2] + arr[1][i]);
		dp[0][i] = mmax(dp[1][i - 1] + arr[0][i], mmax(dp[0][i - 2], dp[1][i - 2]) + arr[0][i]);
		dp[1][i] = mmax(dp[0][i - 1] + arr[1][i], mmax(dp[0][i - 2], dp[1][i - 2]) + arr[1][i]);
	}

	return mmax(dp[0][n], dp[1][n]);
}

void Input() {
	cin >> T;

	while (T--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}

		int max = Solution();
		cout << max << '\n';
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();

	return 0;
}