#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
int arr[8];

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < v.size(); i++) {
		arr[cnt] = v[i];
		dfs(cnt + 1);
	}
}

void Solution() {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	dfs(0);
}

void Input() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}
}

int main() {
	Input();
	Solution();

	return 0;
}