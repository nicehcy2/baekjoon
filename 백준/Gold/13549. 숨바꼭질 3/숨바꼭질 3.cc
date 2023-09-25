#include <iostream>
#include <deque>

#define MAXPOS 200000

using namespace std;

int n, k, pos;
int visited[MAXPOS + 10];

void Input() {
	cin >> n >> k;
}

void bfs(int start) {
	deque<int> dq;
	dq.push_back(start);
	visited[start] = 1;

	while (!dq.empty()) {
		pos = dq.front();
		dq.pop_front();

		if (pos == k) {
			cout << visited[k] - 1 << '\n';
			break;
		}

		// 순간 이동
		if (pos * 2 <= MAXPOS + 1 && !visited[pos * 2]) {
			dq.push_front(pos * 2);
			visited[pos * 2] = visited[pos];
		}

		// x - 1
		if (pos - 1 <= MAXPOS + 1 && !visited[pos - 1]) {
			dq.push_back(pos - 1);
			visited[pos - 1] = visited[pos] + 1;
		}

		// x + 1
		if (pos + 1 <= MAXPOS + 1 && !visited[pos + 1]) {
			dq.push_back(pos + 1);
			visited[pos + 1] = visited[pos] + 1;
		}
	}
}

void Solution() {
	bfs(n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}