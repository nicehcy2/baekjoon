#include <iostream>

using namespace std;

int C, N;
pair<int, int> arr[21];
int dp[100001];

void Input() {

	cin >> C >> N;

	for (int i = 1; i <= N; i++) {

		cin >> arr[i].first >> arr[i].second;
	}
}

void Solution() {

	// dp[i] : i번째 비용으로 얻을 수 있는 고객의 최대값
	for (int i = 1; i <= 20; i++) {

		dp[arr[i].first] = arr[i].second;

		for (int j = 1; j <= 100001; j++) {
			
			if (j - arr[i].first >= 0) {
				dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
			}
		}
	}

	for (int i = 1; i <= 100001; i++) {

		// cout << "dp[" << i << "] = " << dp[i] << '\n';
		if (dp[i] >= C) {
			cout << i << '\n';
			break;
		}
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