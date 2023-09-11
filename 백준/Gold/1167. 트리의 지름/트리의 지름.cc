#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int n;
vector<pair<int, int>> v[1000002];
bool visited[100002];
int maxDistance = 0;
int maxNode = 0;

void InitAndInput() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start;
		cin >> start;

		while (true) {
			int end, distance;
			cin >> end;
			if (end == -1) break;
			cin >> distance;

			v[start].push_back({ distance, end });
		}
	}
}

void dfs(int start, int distance) {
	if (distance > maxDistance) {
		maxDistance = distance;
		maxNode = start;
	}

	for (int i = 0; i < v[start].size(); i++) {
		if (!visited[v[start][i].second]) {
			visited[v[start][i].second] = true;
			dfs(v[start][i].second, distance + v[start][i].first);
		}
	}
}



void Solution() {
	visited[1] = true;
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	visited[maxNode] = true;
	dfs(maxNode, 0);

	cout << maxDistance << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InitAndInput();
	Solution();

	return 0;
}