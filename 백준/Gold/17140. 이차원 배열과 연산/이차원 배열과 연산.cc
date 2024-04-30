#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 1000000000

using namespace std;

int R, C, K;
int A[101][101];
int row = 3, col = 3;

void funcR() {

	for (int i = 1; i <= row; i++) {

		pair<int, int> hash[101];

		for (int i = 0; i < 101; i++) {
			hash[i].first = INF;
		}

		for (int j = 1; j <= col; j++) {

			if (A[i][j] == 0) continue;

			if (hash[A[i][j]].first == INF) hash[A[i][j]].first = 1;
			else hash[A[i][j]].first++;

			hash[A[i][j]].second = A[i][j];
		}

		sort(hash + 1, hash + 101);

		int cnt = 1;
		memset(A[i], 0, sizeof(A[i]));

		for (int j = 1; j < 101; j++) {
			if (hash[j].first != INF) {
				A[i][cnt++] = hash[j].second;
				A[i][cnt++] = hash[j].first;
			}
			else break;
		}

		col = max(col, cnt - 1);
	}
}

void funcC() {

	for (int i = 1; i <= col; i++) {

		pair<int, int> hash[101];

		for (int i = 0; i < 101; i++) {
			hash[i].first = INF;
		}

		for (int j = 1; j <= row; j++) {

			if (A[j][i] == 0) continue;

			if (hash[A[j][i]].first == INF) hash[A[j][i]].first = 1;
			else hash[A[j][i]].first++;

			hash[A[j][i]].second = A[j][i];
		}

		sort(hash + 1, hash + 101);

		int cnt = 1;
		for (int j = 1; j <= 100; j++) {
			A[j][i] = 0;
		}

		for (int j = 1; j < 101; j++) {
			if (hash[j].first != INF) {
				A[cnt++][i] = hash[j].second;
				A[cnt++][i] = hash[j].first;
			}
			else break;

			if (cnt > 100) break;
		}

		row = max(row, cnt - 1);
	}
}

void Solution() {

	int time = 0;

	while (true) {
		if (A[R][C] == K) {
			cout << time << '\n';
			break;
		}
		if (row >= col) funcR();
		else funcC();

		time++;
		if (time > 100) {
			cout << "-1\n";
			break;
		}
	}
}

void Input() {

	cin >> R >> C >> K;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {

			cin >> A[i][j];
		}
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