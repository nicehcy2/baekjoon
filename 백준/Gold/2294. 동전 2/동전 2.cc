#include <iostream>
#include <algorithm>

#define INF 500001

using namespace std;

int n, k;
int coin[101];
int dp[10001];

void Input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin, coin + n);
}

void Solution() {
	dp[0] = 0;

	for (int j = 1; j <= k; j++) {
		if (j % coin[0] == 0) {
			dp[j] = j / coin[0];
		}
		else {
			dp[j] = INF;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			if (dp[j] > dp[j - coin[i]] + 1) {
				dp[j] = dp[j - coin[i]] + 1;
			}
		}
	}

	if (dp[k] != INF) {
		cout << dp[k] << '\n';
	}
	else {
		cout << "-1\n";
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