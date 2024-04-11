#include <iostream>

using namespace std;

int N, stuNum, score;
int arr[25][25];
int like[401][4];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isLike(int num, int ny, int nx) {

	for (int i = 0; i < 4; i++) {
		if (like[num][i] == arr[ny][nx]) return true;
	}

	return false;
}

void calcScore() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int ny = i + dy[d];
				int nx = j + dx[d];

				if (ny >= 1 && ny <= N && nx >= 1 && nx <= N) {

					if (isLike(arr[i][j], ny, nx)) cnt++;
				}
			}

			if (cnt == 4) {
				score += 1000;
			}
			else if (cnt == 3) {
				score += 100;
			}
			else if (cnt == 2) {
				score += 10;
			}
			else if (cnt == 1) {
				score += 1;
			}
		}
	}
}

void Solution() {

	int posY = 0, posX = 0;

	int empty = 0, adj = 0, maxEmpty = -1, maxAdj = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			empty = 0, adj = 0;

			// 이미 칸이 채워지면 다음 칸으로 이동
			if (arr[i][j] != 0) continue;


			// 현재 칸에 인접한 칸에 좋아하는 학생이 몇 명인지 체크
			else if (arr[i][j] == 0) {

				for (int d = 0; d < 4; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];

					if (ny >= 1 && ny <= N && nx >= 1 && nx <= N) {
						if (arr[ny][nx] == 0) {
							empty++;
						}
						else if (arr[ny][nx] > 0) {
							if (isLike(stuNum, ny, nx)) adj++;
						}
					}
				}

				if (adj > maxAdj) {
					posY = i;
					posX = j;
					maxAdj = adj;
					maxEmpty = empty;
				}

				else if (adj == maxAdj) {
					if (empty > maxEmpty) {
						posY = i;
						posX = j;
						maxEmpty = empty;
					}
					else if (empty == maxEmpty) {
						if (posY == i && posX > j) {
							posX = j;
						}
						else if (posY > i) {
							posX = j;
							posY = i;
						}
					}
				}
			}
		}
	}

	arr[posY][posX] = stuNum;
}

void Input() {

	cin >> N;

	for (int i = 0; i < N * N; i++) {
		
		cin >> stuNum;

		for (int j = 0; j < 4; j++) {
			cin >> like[stuNum][j];
		}

		Solution();
	}


	calcScore();
	cout << score << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	// Solution();

	return 0;
}