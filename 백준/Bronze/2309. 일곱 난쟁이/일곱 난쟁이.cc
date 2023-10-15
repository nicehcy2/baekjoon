#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int v[10];
bool visited[10];
bool flag = false;

void Input() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
}

void dfs(int idx, int sum) {
	if (idx == 7 && sum == 100) {
		sort(v, v + 7);
		flag = true;
		for (int i = 0; i < 7; i++) {
			cout << v[i] << '\n';
		}

		return;
	}
	if (idx == 7 && sum != 100) {
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (flag) {
			return;
		}

		if (!visited[i]) {
			visited[i] = true;
			v[idx] = arr[i];
			dfs(idx + 1, sum + arr[i]);
			visited[i] = false;
		}
	}
}

void Solution() {
	dfs(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}