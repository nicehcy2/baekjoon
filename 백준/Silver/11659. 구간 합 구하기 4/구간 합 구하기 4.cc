#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int n, m;
int arr[100001];

void InitAndInput() {
	cin >> n >> m;
	cin >> arr[1];
	for (int i = 2; i <= n; i++) {
		cin >> arr[i];
		arr[i] = arr[i - 1] + arr[i];
	}
}

void Solution() {
	int sum = 0;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		cout << arr[y] - arr[x - 1] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InitAndInput();
	Solution();

	return 0;
}