#include <iostream>

using namespace std;

#define INF 1000000000

int n;
int dp[50001];


void Solution() {
	int res = n;
	fill(dp + 0, dp + n + 1, INF);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n] << '\n';
}

void Input() {
	cin >> n;
}

int main() {
	Input();
	Solution();

	return 0;
}