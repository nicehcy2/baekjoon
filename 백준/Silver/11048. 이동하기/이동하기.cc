#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1001][1001], dp[1001][1001];

int bigger(int a, int b) {
	if (a >= b) return a;
	else return b;
}

void Solution() {
	dp[1][1] = arr[1][1];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = bigger(arr[i][j] + dp[i - 1][j], arr[i][j] + dp[i][j - 1]);
		}
	}

	cout << dp[N][M] << '\n';
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
}

int main() {
	Input();
	Solution();

	return 0;
}