#include <iostream>

#define MOD 10007

using namespace std;

int N;
int dp[1010];

void Input() {

	cin >> N;
}

void Solution() {
	
	
	dp[1] = 1, dp[2] = 2, dp[3] = 3;
	for (int i = 4; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
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