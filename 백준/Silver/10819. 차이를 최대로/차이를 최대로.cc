#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int n, mmax = 0;
int arr[9];
bool visited[9];

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void dfs(int idx, int cnt, int sum) {
	if (cnt == n) {
		if (sum > mmax) {
			mmax = sum;
		}

		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, cnt + 1, sum + abs(arr[i] - arr[idx]));
			visited[i] = false;
		}
	}
}

void Solution() {
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		visited[i] = true;
		dfs(i, 1, 0);
	}

	cout << mmax << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}