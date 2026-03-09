#include <iostream>
#include <algorithm>
#pragma warning disable:4996

using namespace std;

int mapX, mapY;
int originalMap[9][9];
int map[9][9];
bool check[9][9];
int virusX[65];
int virusY[65];
int virusCnt = 0;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, +1, 0, -1 };

void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (map[nextY][nextX] == 0  && 
			0 <= nextY && nextY < mapY && 0 <= nextX && nextX < mapX) {
			if (map[nextY][nextX] == 0)
				map[nextY][nextX] = 2;
			dfs(nextY, nextX);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0, ans = 0;
	int x1, y1, x2, y2, x3, y3;

	cin >> mapY >> mapX;

	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			int num;
			cin >> num;
			map[i][j] = num;
			originalMap[i][j] = num;

			if (map[i][j] == 2) {
				virusX[virusCnt] = j;
				virusY[virusCnt] = i;
				virusCnt++;
			}
		}
	}

	
	for (int i = 0; i < mapX * mapY; i++) {
		x1 = i % mapY, y1 = i / mapY;
		if (map[x1][y1] == 0) {
			for (int j = i + 1; j < mapX * mapY; j++) {
				x2 = j % mapY, y2 = j / mapY;
				if (map[x2][y2] == 0) {
					for (int k = j + 1; k < mapX * mapY; k++) {
						x3 = k % mapY, y3 = k / mapY;
						if (map[x3][y3] == 0) {
							map[x1][y1] = 1;
							map[x2][y2] = 1;
							map[x3][y3] = 1;

							for (int p = 0; p < virusCnt; p++) {
								dfs(virusY[p], virusX[p]);
							}

							cnt = 0;
							for (int p = 0; p < mapY; p++) {
								for (int q = 0; q < mapX; q++) {
									if (map[p][q] == 0) {
										cnt++;
									}
								}
							}

							if (cnt > ans) {
								ans = cnt;
							}

							for (int p = 0; p < mapY; p++) {
								for (int q = 0; q < mapX; q++) {
									map[p][q] = originalMap[p][q];
								}
							}
						}
					}
				}
			}
		}
	}

	cout << ans;

	return 0;
}