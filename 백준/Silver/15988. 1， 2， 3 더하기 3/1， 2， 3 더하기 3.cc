#include <iostream>
#include <cstring>

#define MOD 1000000009

using namespace std;

long long dp[1000010];

void Input() {
}

void Solution() {

	int T; cin >> T;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (T--) {
		int N; cin >> N;
		
		for (int j = 4; j <= N; j++) {

			dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % MOD;
		}
		cout << dp[N] % MOD << '\n';
		
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Input();
	Solution();

	return 0;
}
	