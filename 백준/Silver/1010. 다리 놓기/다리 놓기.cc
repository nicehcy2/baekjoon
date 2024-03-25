#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int t, n, m;

int Solution(int n, int m) {
	long long int ans = 1;

	if (n < (m / 2)) {
		for (int i = 0; i < n; i++) {
			ans *= (m - i);
			ans /= (i + 1);
		}
	}
	else {
		for (int i = 0; i < (m - n); i++) {
			ans *= (m - i);
			ans /= (i + 1);
		}

	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << Solution(n, m) << '\n';
	}

	return 0;
}