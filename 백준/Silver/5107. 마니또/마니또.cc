#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>

using namespace std;

int N, cnt = 1, res = 0;
string from, to;
vector<pair<string, string>> ma;
vector<pair<string, int>> name;
int node[21];
bool visited[21];

bool bfs(int i) {
	int init = i;
	visited[i] = true;
	queue<int> q;
	q.push(i);

	while (!q.empty()) {
		int next = node[q.front()];
		q.pop();
		if (next == init) {
			return true;
		}

		if (!visited[next]) {
			q.push(next);
			visited[next] = true;
		}
	}

	return false;
}

void Solution() {
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			if (bfs(i)) {
				res++;
			}
		}
	}

	cout << cnt++ << " " << res << '\n';
}

int FindString(string str) {
	for (int i = 0; i < name.size(); i++) {
		if (name[i].first == str) {
			return i;
		}
	}
}

void Input() {
	while (true) {
		cin >> N;
		if (!N) return;

		memset(node, 0, sizeof(node));
		memset(visited, 0, sizeof(visited));
		ma.clear();
		name.clear();
		res = 0;

		for (int i = 0; i < N; i++) {
			cin >> from >> to;
			ma.push_back({ from, to });
			name.push_back({ from, i });
		}
		for (int i = 0; i < N; i++) {
			int num = FindString(ma[i].second);
			node[i] = num;
		}

		Solution();
	}
}

int main() {
	Input();
	//Solution();

	return 0;
}