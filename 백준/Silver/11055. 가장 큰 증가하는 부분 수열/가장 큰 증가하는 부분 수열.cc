#include <iostream>

using namespace std;

int N;
int dp[1002], arr[1001];

void Input() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}


void Solution() {

	for (int i = 0; i < N; i++) {
		
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			
			if (arr[i] > arr[j]) dp[i] = max(dp[j] + arr[i], dp[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}