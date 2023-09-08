#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int n;
// 인접 리스트
vector<int> v[100001];
int visited[100001];

void InitAndInput() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v[start].push_back(end);
		v[end].push_back(start);
	}
}

void dfs(int start, int parent) {
	visited[start] = parent;

	for (int i = 0; i < v[start].size(); i++) {
		if (!visited[v[start][i]]) {
			dfs(v[start][i], start);
		}
	}
}

void Solution() {
	visited[1] = 1;
	dfs(1, 1);

	for (int i = 2; i <= n; i++) {
		cout << visited[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InitAndInput();
	Solution();

	return 0;
}