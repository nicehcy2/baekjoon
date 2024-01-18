#include <iostream>

using namespace std;

#define DIVISOR 1000000000

int N, K;
int dp[205][205];

void Solution() {
	// init
	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int k = 2; k <= K; k++) {
		dp[k][0] = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				dp[k][i] = (dp[k - 1][j] + dp[k][i]) % DIVISOR;
			}
		}
	}

	cout << dp[K][N] % DIVISOR << '\n';
}

void Input() {
	cin >> N >> K;
}

int main() {
	Input();
	Solution();

	return 0;
}