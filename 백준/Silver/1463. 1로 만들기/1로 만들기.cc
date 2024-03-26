#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#include <string>
#include <cstdlib>
#include <sstream>
#include <deque>
#pragma warning(disable:4996)
using namespace std;

vector<int> dp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp.resize(n + 1, 0);

	dp[1] = 0;
	dp[2] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[n];

	return 0;
}