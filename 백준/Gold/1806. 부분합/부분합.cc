#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define INF 2100000000

using namespace std;

int n, s;
int arr[100001];

void InitAndInput() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
}

void Solution() {
	int start = 1, end = 1, prefixSum = 0, count = 0, min = INF;

	while (true) {
		if (start == n + 1) {
			break;
		}
		prefixSum = arr[end] - arr[start - 1];

		if (prefixSum < s) {
			if (end + 1 <= n)
				end++;
			else {
				start++;
			}
		}

		else if (prefixSum >= s) {
			if (end - start + 1 < min) {
				min = end - start + 1;
			}

			start++;
		}
	}

	if (min == INF) cout << 0 << '\n';
	else cout << min << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InitAndInput();
	Solution();

	return 0;
}