#include <iostream>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

int N, M;
int arr[1005][1005];
int grouped[1005000];
bool visited[1005][1005];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int num = 1, ans;

void bfs(int y, int x) {

	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;
	arr[y][x] = num;
	grouped[num] += 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (arr[ny][nx] && visited[ny][nx] == false) {
					q.push({ ny, nx });
					visited[ny][nx] = true;
					arr[ny][nx] = num;
					grouped[num] += 1;
				}
			}
		}
	}
}

void findGroup(int y, int x) {
	
	int sum = 1;
	map<int, int> plus;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
			plus[arr[ny][nx]] = grouped[arr[ny][nx]];
		}
	}

	for (auto o : plus) {
		sum += o.second;
	}

	ans = max(ans, sum);
}

void Input() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
}

void Solution() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && arr[i][j]) {
				bfs(i, j);
				num++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			if (arr[i][j] == 0) {
				findGroup(i, j);
			}
		}
	}

	cout << ans << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}