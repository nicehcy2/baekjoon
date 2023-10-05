#include <iostream>

using namespace std;

int n, m, k;
int arr[301][301];

void Input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> k;
	while(k--) {
		int a, b, c, d, sum = 0;
		cin >> a >> b >> c >> d;

		for (int i = b; i <= d; i++) {
			for (int j = a; j <= c; j++) {
				sum += arr[j][i];
			}
		}

		cout << sum << '\n';
	}

}

void Solution() {

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}