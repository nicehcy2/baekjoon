#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> arr[2001];
bool visited[2001];

void Input() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {

		int from, to; cin >> from >> to;

		arr[from].push_back(to);
		arr[to].push_back(from);
	}
}

void BackTracking(int cur, int depth) {

	visited[cur] = true;

	if (depth == 4) {
		cout << "1\n";
		exit(0);
	}

	for (int i = 0; i < arr[cur].size(); i++) {
		
		if (visited[arr[cur][i]] == false) {
			BackTracking(arr[cur][i], depth + 1);
			visited[arr[cur][i]] = false;
		}
	}
}

void Solution() {

	for (int i = 0; i < N; i++) {

		memset(visited, false, sizeof(visited));
		BackTracking(i, 0);
	}

	cout << "0\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}