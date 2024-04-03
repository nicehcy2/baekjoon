#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1001][1001];
bool visited[1001][1001];
int dist[1001][1001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

pair<int, int> start;

void bfs(int y, int x) {

	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push({ y, x });

	while (!q.empty()) {

		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && visited[ny][nx] == false && arr[ny][nx] == 1) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
				dist[ny][nx] = dist[cy][cx] + 1;
			}
		}
	}
}

void Input() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> arr[i][j];

			if (arr[i][j] == 2) start = { i, j };
		}
	}
}

void Solution() {

	bfs(start.first, start.second);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (arr[i][j] == 1 && dist[i][j] == 0) {
				dist[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cout << dist[i][j] << " ";
		}
		cout << '\n';
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