#include <iostream>

using namespace std;

int M, N;
int arr[501][501], dp[501][501];
bool visited[501][501];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(int y, int x) {
	if (y == M - 1 && x == N - 1) {
		return dp[M - 1][N - 1] = 1;
	}
	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	// dp가 -1일 경우에만 새로운 경로 탐색(방문하지 않은 경로이므로)
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < M && nx >= 0 && nx < N) {
			if (arr[y][x] > arr[ny][nx]) {
				dp[y][x] += dfs(ny, nx);
			}
		}
	}

	return dp[y][x];
}

void Solution() {
	cout << dfs(0, 0) << '\n';
}

void Input() {
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
}

int main() {
	Input();
	Solution();

	return 0;
}