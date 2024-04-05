#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];

bool valid(int n) {
	if (n < 0 || n > 100000 || visited[n]) return false;
	else return true;
}

void Input() {

	cin >> N >> K;
}

void bfs(int n) {

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty()) {

		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		if (cur == K) {
			cout << time << '\n';
			exit(0);
		}

		if (valid(cur - 1)) {
			visited[cur - 1] = true;
			q.push({ cur - 1, time + 1 });
		}

		if (valid(cur + 1)) {
			visited[cur + 1] = true;
			q.push({ cur + 1, time + 1 });
		}

		if (valid(2 * cur)) {
			visited[2 * cur] = true;
			q.push({ 2 * cur, time + 1});
		}
	}
}

void Solution() {

	bfs(N);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}