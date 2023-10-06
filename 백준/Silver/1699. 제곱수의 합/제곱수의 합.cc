#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

#define INF 2100000000

using namespace std;

int n;
vector<int> v;
int dp[100001];

int minDp(int a, int b) {
	return a < b ? a : b;
}

void Input() {
	cin >> n;
}

void Solution() {
	int min = INF;

	// 더할 수 있는 모든 제곱수 찾기
	for (int i = 1; i <= n; i++) {
		if (pow(i, 2) <= n) {
			v.push_back(pow(i, 2));
		}
		else {
			break;
		}
	}

	for (int i = 0; i <= n; i++) {
		dp[i] = INF;
	}
	dp[0] = 0;

	for (int i = 0; i < v.size(); i++) {
		for (int j = dp[i]; j <= n; j++) {
			dp[j] = minDp(dp[j], j / v[i] + dp[j % v[i]]);
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