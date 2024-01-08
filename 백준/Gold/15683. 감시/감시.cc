#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000
#define AIR 0
#define WALL 6
#define AREA 10

int N, M, cctvCnt, answer = INF;
int arr[9][9];
vector<pair<int, int>> cctv;

int dy[4] = { 0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

vector<vector<int>> SimulateMap(int dir, int cnt, vector<vector<int>> map) {
	int y = cctv[cnt].first;
	int x = cctv[cnt].second;

	while (true) {
		y += dy[dir % 4];
		x += dx[dir % 4];
		if (y >= 0 && y < N && x >= 0 && x < M) {
			if (map[y][x] != WALL) {
				if (map[y][x] == AIR) {
					map[y][x] = AREA;
				}
				else if (map[y][x] >= 1 && map[y][x] <= 5) {
					continue;
				}
			}
			else {
				return map;
			}
		}
		else {
			return map;
		}
	}

	return map;
}

int countRes(vector<vector<int>> map) {
	int res = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				res++;
			}
		}
	}

	return res;
}

void BackTracking(int cnt, vector<vector<int>> map) {
	if (cnt == cctvCnt) {
		int res = countRes(map);
		if (res < answer) {
			answer = res;
		}

		return;
	}

	vector<vector<int>> copy = map;
	int y = cctv[cnt].first;
	int x = cctv[cnt].second;
	for (int i = 0; i < 4; i++) {
		if (map[y][x] == 1) {
			map = SimulateMap(i, cnt, map);
			BackTracking(cnt + 1, map);
			map = copy;
		}
		else if (map[y][x] == 2) {
			map = SimulateMap(i, cnt, map);
			map = SimulateMap(i + 2, cnt, map);
			BackTracking(cnt + 1, map);
			map = copy;
		}
		else if (map[y][x] == 3) {
			map = SimulateMap(i, cnt, map);
			map = SimulateMap(i + 1, cnt, map);
			BackTracking(cnt + 1, map);
			map = copy;
		}
		else if (map[y][x] == 4) {
			map = SimulateMap(i, cnt, map);
			map = SimulateMap(i + 1, cnt, map);
			map = SimulateMap(i + 2, cnt, map);
			BackTracking(cnt + 1, map);
			map = copy;
		}
		else if (map[y][x] == 5) {
			map = SimulateMap(i, cnt, map);
			map = SimulateMap(i + 1, cnt, map);
			map = SimulateMap(i + 2, cnt, map);
			map = SimulateMap(i + 3, cnt, map);
			BackTracking(cnt + 1, map);
			map = copy;
		}
	}
}

void Solution() {
	vector<vector<int>> map;

	cctvCnt = cctv.size();

	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < M; j++) {
			v.push_back(arr[i][j]);
		}
		map.push_back(v);
	}

	BackTracking(0, map);

	cout << answer << '\n';
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];

			// CCTV 좌표 저장
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				cctv.push_back({ i, j });
			}
		}
	}
}

int main() {
	Input();
	Solution();

	return 0;
}