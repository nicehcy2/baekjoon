#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
int A[51][51];
pair<int, int> command[101];
vector<pair<int, int>> cloud, newCloud;
bool visited[51][51];

int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int checkDiag(int cy, int cx) {

	int cnt = 0;
	int dirY[4] = { -1, -1, 1, 1 };
	int dirX[4] = { -1, 1, 1, -1 };
	
	for (int i = 0; i < 4; i++) {
		int ny = cy + dirY[i];
		int nx = cx + dirX[i];

		if (ny >= 1 && ny <= N && nx >= 1 && nx <= N) {
			if (A[ny][nx] != 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

void createCloud() {
	cloud.clear();
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] >= 2 && visited[i][j] == false) {
				cloud.push_back({ i, j });
				A[i][j] -= 2;
			}
		}
	}

	memset(visited, false, sizeof(visited));
}

int sumWater() {

	int value = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			value += A[i][j];
		}
	}

	return value;
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << A[i][j] << " ";
		}
		cout << '\n';
	}
}

int checkIdx(int x) {
	if (x < 1) return N;
	if (x > N) return 1;
	return x;
}

void Solution() {

	cloud.push_back({ N - 1, 1 });
	cloud.push_back({ N - 1, 2 });
	cloud.push_back({ N, 1 });
	cloud.push_back({ N, 2 });
	
	for (int i = 0; i < M; i++) {

		int dir = command[i].first;
		int dist = command[i].second;

		for (int j = 0; j < cloud.size(); j++) {

			int ny = cloud[j].first;
			int nx = cloud[j].second;

			for (int k = 0; k < dist; k++) {
				ny += dy[dir];
				nx += dx[dir];
				ny = checkIdx(ny);
				nx = checkIdx(nx);
			}

			newCloud.push_back({ ny, nx });
			A[ny][nx]++;
			visited[ny][nx] = true;
		}

		cloud.clear();
		cloud = newCloud;
		newCloud.clear();

		for (int j = 0; j < cloud.size(); j++) {

			int cy = cloud[j].first;
			int cx = cloud[j].second;
			int cnt = checkDiag(cy, cx);

			A[cy][cx] += cnt;
		}

		createCloud();

		//cout << '\n';
		//print();
		//cout << '\n';
	}

	cout << sumWater() << '\n';
}

void Input() {
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> command[i].first >> command[i].second;
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