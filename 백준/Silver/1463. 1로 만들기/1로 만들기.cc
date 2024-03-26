#include <iostream>
#include <cmath>

using namespace std;

int N;
int dp[1000010];

void Input() {
	
	cin >> N;
}

void Solution() {

	dp[1] = 0, dp[2] = 1;
	
	for (int i = 2; i <= N; i++) {

		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0) {
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
		
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
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