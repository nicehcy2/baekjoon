#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, m;
char arr[51][51];
int visited[51][51];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
			
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			if (nextY < n && nextY >= 0 && nextX < m && nextX >= 0) {
				if (visited[nextY][nextX] == 0 && arr[nextY][nextX] == 'L') {
					q.push({ nextY, nextX });
					visited[nextY][nextX] = visited[curY][curX] + 1;
				}
			}
		}
	}
}

int checkMaxValue() {
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < visited[i][j]) {
				max = visited[i][j];
			}
		}
	}

	return max;
}

void Solution() {
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				bfs(i, j);
			}

			int curValue = checkMaxValue();
			if (curValue > max) {
				max = curValue;
			}
			memset(visited, 0, sizeof(visited));
		}
	}

	/*
	bfs(1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
	*/

	cout << max - 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}