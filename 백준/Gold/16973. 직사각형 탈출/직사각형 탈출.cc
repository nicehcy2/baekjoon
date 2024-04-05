#include <iostream>
#include <queue>

using namespace std;

int N, M, H, W, SY, SX, DY, DX;
int arr[1001][1001];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int visited[1005][1005];

void Input() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> H >> W >> SY >> SX >> DY >> DX;
}

bool valid(int y, int x, int d) {

	if (visited[y][x]) return false;

	if (y < 1 || y + H - 1 > N || x < 1 || x + W - 1 > M) return false;

	if (d == 0) {
		for (int i = y; i < y + H; i++) {
			if (arr[i][x + W - 1]) return false;
		}
	}
	else if (d == 1) {
		for (int i = x; i < x + W; i++) {
			if (arr[y + H - 1][i]) return false;
		}
	}
	else if (d == 2) {
		for (int i = y; i < y + H; i++) {
			if (arr[i][x]) return false;
		}
	}
	else if (d == 3) {
		for (int i = x; i < x + W; i++) {
			if (arr[y][i]) return false;
		}
	}

	return true;
}

void bfs(int y, int x) {

	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });

	while (!q.empty()) {

		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		if (cy == DY && cx == DX) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (valid(ny, nx, i)) {
				q.push({ ny, nx });
				visited[ny][nx] = visited[cy][cx] + 1;
			}
		}
	}
}

void Solution() {

	bfs(SY, SX);

	/*
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}*/

	if (visited[DY][DX]) cout << visited[DY][DX] - 1 << '\n';
	else cout << "-1\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}