#include <iostream>
#include <algorithm>
#include <queue>
#pragma warning disable:4996

using namespace std;

int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n + 1; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n + 1];

	return 0;
}