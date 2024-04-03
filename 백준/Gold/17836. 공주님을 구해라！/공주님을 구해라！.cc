#include <iostream>
#include <queue>

using namespace std;

#define INF 1000000000

int N, M, T;
int arr[101][101];
int visited[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int swordAns = INF;

void bfs(int y, int x) {

	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });

	while (!q.empty()) {

		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && visited[ny][nx] == 0) {

				if (arr[ny][nx] == 2) {
					q.push({ ny, nx });
					visited[ny][nx] = visited[cy][cx] + 1;

					swordAns = visited[ny][nx] + (N - ny - 1) + (M - nx - 1);
				}
				else if (arr[ny][nx] == 0) {
					q.push({ ny, nx });
					visited[ny][nx] = visited[cy][cx] + 1;
				}
			}
		}
	}
}

void Input() {

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> arr[i][j];
		}
	}
}

void Solution() {

	bfs(0, 0);

	int ans = visited[N - 1][M - 1] - 1;
	swordAns -= 1;

	// 벽을 안넘고 갈 수 있는 경우
	if (ans > -1 && ans <= T) {
		ans = min(ans, swordAns);

		if (ans <= T) cout << ans << '\n';
		else cout << "Fail\n";
	}
	else {

		if (swordAns > T) cout << "Fail\n";
		else cout << swordAns << '\n';
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