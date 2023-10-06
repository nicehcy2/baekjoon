#include <iostream>

using namespace std;

int n;
int dp[16], T[16], P[16];

void Input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}
}

void Solution() {
	int max = 0;

	for (int i = n; i >= 1; i--) {
		int checkDay = i + T[i];
		if (checkDay <= n + 1) {
			int curMax = 0;
			for (int j = checkDay; j <= n; j++) {
				if (curMax < dp[j]) {
					curMax = dp[j];
				}
			}
			dp[i] = curMax + P[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (max <= dp[i]) {
			max = dp[i];
		}
	}

	cout << max << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}