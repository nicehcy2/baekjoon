#include <iostream>
#include <queue>

using namespace std;

int N, K, result = 0, MIN = 0;
bool visited[200002];
bool first = true;

bool Valid(int x) {
	if (visited[x] || x > 100000 || x < 0) return false;
	else return true;
}

void Input() {
	
	cin >> N >> K;
}

void bfs(int x) {

	queue<pair<int, int>> q;
	visited[x] = true;
	q.push({ x, 0 });

	while (!q.empty()) {

		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		// bfs여서 가능한 상황
		// 부모 노드가 세 갈래로 뻗으면서 queue에 넣은 다음에 visited이 동작하므로 
		// queue에 넣을 떄는 visited에 걸리지 않는다.
		visited[cur] = true;

		if (!first && MIN == time && cur == K) {
			result++;
		}

		if (!first && MIN < time) {
			break;
		}
		
		if (first && cur == K) {
			MIN = time;
			first = false;
			result++;
		}

		if (Valid(cur + 1)) {
			q.push({ cur + 1, time + 1 });
		}

		if (Valid(cur - 1)) {
			q.push({ cur - 1, time + 1 });
		}

		if (Valid(2 * cur)) {
			q.push({ 2 * cur, time + 1 });
		}
	}
}

void Solution() {

	bfs(N);

	cout << MIN << '\n' << result << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}