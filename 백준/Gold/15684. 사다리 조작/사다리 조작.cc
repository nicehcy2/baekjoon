#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000

int N, M, H, res = INF;
int ladder[11][31];

int ClimbingLadder(int i) {
	int curN = i;

	for (int height = 1; height <= H; height++) {
		if (ladder[curN][height] >= 1 && ladder[curN][height] <= N) {
			curN = ladder[curN][height];
		}
	}

	return curN;
}

bool CheckLadder() {
	for (int i = 1; i <= N; i++) {
		if (ClimbingLadder(i) != i) return false;
	}

	return true;
}

void dfs(int cnt, int start) {
	if (cnt == 4) {
		return;
	}

	if (CheckLadder()) {
		if (cnt < res) {
			res = cnt;
		}
		return;
	}

	for (int i = start; i < N; i++) {
		for (int j = 1; j <= H; j++) {
			if (ladder[i][j] == 0 && ladder[i + 1][j] == 0) {
				ladder[i][j] = i + 1;
				ladder[i + 1][j] = i;

				dfs(cnt + 1, i);

				ladder[i][j] = 0;
				ladder[i + 1][j] = 0;
			}
		}
	}
}

void Solution() {
	dfs(0, 1);

	if (res == INF) {
		cout << "-1\n";
	}
	else {
		cout << res << '\n';
	}
}

void Input() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[b][a] = b + 1;
		ladder[b + 1][a] = b;
	}
}

int main() {
	Input();
	Solution();

	return 0;
}