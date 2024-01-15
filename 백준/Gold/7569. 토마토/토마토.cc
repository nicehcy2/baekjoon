#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int arr[111][111][111], visited[111][111][111];

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

class Node {
public:
	int h, y, x;

	Node(int hh, int yy, int xx) : h(hh), y(yy), x(xx) {}	
};

queue<Node> q;

int checkCount() {
	int max = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[i][j][k] == 0) {
					return -1;
				}
				if (visited[i][j][k] > max) {
					max = visited[i][j][k];
				}
			}
		}
	}

	return max - 1;
}

void bfs() {
	while (!q.empty()) {
		int ch, cy, cx;
		ch = q.front().h;
		cy = q.front().y;
		cx = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh, ny, nx;
			nh = ch + dh[i];
			ny = cy + dy[i];
			nx = cx + dx[i];

			if (nh >= 0 && nh < H && ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (!visited[nh][ny][nx]) {
					if (arr[nh][ny][nx] == 0) {
						arr[nh][ny][nx] = 1;
						q.push(Node(nh, ny, nx));
						visited[nh][ny][nx] = visited[ch][cy][cx] + 1;
					}
					else if (arr[nh][ny][nx] == 1) {
						q.push(Node(nh, ny, nx));
						visited[nh][ny][nx] = visited[ch][cy][cx];
					}
				}
			}
		}
	}
}

void Solution() {
	bfs();

	cout << checkCount() << '\n';
}

void Input() {
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push(Node(i, j, k));
					visited[i][j][k] = 1;
				}
			}
		}
	}
}

int main() {
	Input();
	Solution();

	return 0;
}