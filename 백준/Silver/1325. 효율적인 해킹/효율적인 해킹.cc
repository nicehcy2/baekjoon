#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> g[10001];
vector<int> ans;
bool visited[10001];
int cnt = 0;

void Input() {

	cin >> N >> M;

	int A, B;

	for (int i = 0; i < M; i++) {
		
		cin >> B >> A;

		g[A].push_back(B);
	}
}

void dfs(int node) {

	visited[node] = true;
	cnt++;

	for (int i = 0; i < g[node].size(); i++) {
		
		if (visited[g[node][i]] == false)
			dfs(g[node][i]);
	}
}

void Solution() {
	
	int max = 0;

	for (int i = 1; i <= N; i++) {

		memset(visited, 0, sizeof(visited));
		cnt = 0;

		dfs(i);

		if (max < cnt) {
			max = cnt;
			ans.clear();
			ans.push_back(i);
		}
		else if (max == cnt) {
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}