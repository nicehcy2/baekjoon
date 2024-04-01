#include <iostream>

using namespace std;

int N, M;
int arr[1025][1025];

void Input() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			cin >> arr[i][j];

			arr[i][j] += arr[i - 1][j];
		}
	}
}

void Solution() {

	int x1, y1, x2, y2, sum = 0;

	for (int i = 0; i < M; i++) {
		
		cin >> y1 >> x1 >> y2 >> x2;

		for (int x = x1; x <= x2; x++) {

			sum += (arr[y2][x] - arr[y1 - 1][x]);
		}

		cout << sum << '\n';
		sum = 0;
	}
}

int main() {

	ios::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}