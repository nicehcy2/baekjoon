#include <iostream>
#include <vector>;
#include <algorithm>

using namespace std;

int n;
int dp[31];

void Input() {
	cin >> n;

	dp[0] = 1, dp[1] = 0, dp[2] = 3;
}

void Solution() {
	if (n % 2 != 0 || n == 0) {
		cout << "0\n";
		return;
	}

	for (int i = 4; i <= n; i += 2) {
		int cur = i, cnt = 0;
		while (true) {
			if (cur < 0) {
				break;
			}

			if (!cnt) {
				dp[cur + cnt] += dp[cur - 2] * dp[2];
			}
			else {
				dp[cur + cnt] += dp[cur - 2] * 2;
			}
			cur -= 2;
			cnt += 2;
		}
	}

	cout << dp[n] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}