#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int arr[101];
bool visited[101], ans[101];

void Input() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

		if (arr[i] == i) ans[i] = true;
	}
}

void dfs(int cur, int root, vector<int> v) {

	visited[cur] = true;
	v.push_back(cur);

	if (arr[cur] == root) {
		
		for (int i = 0; i < v.size(); i++) {
			ans[v[i]] = true;
		}
	}
	
	if (visited[arr[cur]] == false)
		dfs(arr[cur], root, v);
}

void Solution() {

	vector<int> v;

	for (int i = 1; i <= N; i++) {

		memset(visited, false, sizeof(visited));
		dfs(i, i, v);
	}

	int cnt = 0;
	for (int i = 1; i < 101; i++) {
		if (ans[i]) cnt++;
	}

	cout << cnt << '\n';

	for (int i = 1; i < 101; i++) {
		if (ans[i]) cout << i << '\n';
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