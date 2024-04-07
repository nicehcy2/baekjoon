#include <iostream>
#include <queue>

using namespace std;

int R, C;

char arr[1002][1002];
int visited[1002][1002];

queue<pair<int, int>> jq, fq;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool bfs() {

	while (!jq.empty()) {
		int rootSize = jq.size();

		for (int cnt = 0; cnt < rootSize; cnt++) {
			int cy = jq.front().first;
			int cx = jq.front().second;
			jq.pop();

			if (arr[cy][cx] == 'F') {
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny >= 1 && ny <= R && nx >= 1 && nx <= C) {
					if (arr[ny][nx] != '#' && arr[ny][nx] != 'F' && visited[ny][nx] == 0) {
						jq.push({ ny, nx });
						visited[ny][nx] = visited[cy][cx] + 1;
					}
				}
				if (ny == 0 || ny == R + 1 || nx == 0 || nx == C + 1) {
					cout << visited[cy][cx] << '\n';
					return true;
				}
			}
		}

		int fireSize = fq.size();

		for (int i = 0; i < fireSize; i++) {

			int cy = fq.front().first;
			int cx = fq.front().second;
			fq.pop();

			for (int d = 0; d < 4; d++) {
				int ny = cy + dy[d];
				int nx = cx + dx[d];

				if (ny >= 1 && ny <= R && nx >= 1 && nx <= C) {

					if (arr[ny][nx] != '#' && arr[ny][nx] != 'F') {
						fq.push({ ny, nx });
						arr[ny][nx] = 'F';
					}
				}

			}
		}
	}

	return false;
}

void Input() {

	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {

			cin >> arr[i][j];

			if (arr[i][j] == 'J') {
				jq.push({ i, j });
				visited[i][j] = 1;
			}
			else if (arr[i][j] == 'F') {
				fq.push({ i, j });
			}
		}
	}	
}

void Solution() {
	
	if (!bfs()) cout << "IMPOSSIBLE\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}