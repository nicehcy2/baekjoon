#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

struct Node {
	int y, x, wall;
};

int map[1001][1001], visited[1001][1001][2], res[1001][1001];
string str;
int N, M;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

bool bfs(int y, int x) {
	queue<Node> q;
	q.push({ y, x, 0 });
	visited[y][x][0] = 1;
	visited[y][x][1] = 1;
	res[1][1] = 1;
	int cnt = 0;

	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		int wall = q.front().wall;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= M ) {
				if (visited[nextY][nextX][wall] == 0 && map[nextY][nextX] == 0) {
					q.push({ nextY, nextX, wall });
					visited[nextY][nextX][wall] = true;
					res[nextY][nextX] = res[curY][curX] + 1;
				}

				if (visited[nextY][nextX][wall + 1] == 0 && wall == 0 && map[nextY][nextX] == 1) {
					q.push({ nextY, nextX, wall + 1 });
					visited[nextY][nextX][wall + 1] = true;
					res[nextY][nextX] = res[curY][curX] + 1;
				}
				
				if (nextY == N && nextX == M) {
					cout << res[N][M] << '\n';
					return true;
				}
			}
		}
	}

	return false;
}

void Solution() {
	if (N == 1 && M == 1)
	{
		cout << 1;
		return;
	}

	if (!bfs(1, 1)) {
		cout << "-1\n";
	}
}

void Input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j + 1] = str[j] - '0';
		}
	}
}

int main() {
	Input();
	Solution();

	return 0;
}