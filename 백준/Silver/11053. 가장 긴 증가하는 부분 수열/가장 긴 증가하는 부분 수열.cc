#include <iostream>
#include <algorithm>

using namespace std;

int mmax(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int n, A[1001], dp[1001], len = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				dp[i] = mmax(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (dp[i] > len) {
			len = dp[i];
		}
	}

	cout << len;

	return 0;
}