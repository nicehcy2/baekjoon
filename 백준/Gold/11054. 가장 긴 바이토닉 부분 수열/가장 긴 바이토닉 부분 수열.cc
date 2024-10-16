#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, arr[1002], maxDp[1002], minDp[1002];

int mmax(int a, int b) {
	if (a > b) return a;
	else return b;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	maxDp[0] = 1;

	for (int i = 1; i < n; i++) {
		maxDp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				// dp[i]의 존재는 최대값이 아닐 때 값이 갱신 되는 것을 방지
				maxDp[i] = mmax(maxDp[i], maxDp[j] + 1);
				
			}
		}
	}

	int maxIdx = 0, max = 0;
	for (int i = 0; i < n; i++) {
		if (max < maxDp[i]) {
			max = maxDp[i];
			maxIdx = i;
		}
	}

	for (int i = n - 1; i>= 0; i--) {
		for (int j = n - 1; j >= i; j--) {
			if (arr[i] > arr[j]) {
				minDp[i] = mmax(minDp[i], minDp[j] + 1);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result = mmax(maxDp[i] + minDp[i], result);
	}

	cout << result;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}