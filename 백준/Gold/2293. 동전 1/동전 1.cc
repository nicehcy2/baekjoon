#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[101];
int dp[10001];

void Input() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void Solution() {
	
	sort(arr, arr + N);

	dp[0] = 1;

	for (int i = 0; i < N; i++) {

		for (int j = arr[i]; j <= K; j++) {

			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[K] << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}