#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
vector<int> v;
int arr[8];

void dfs(int cnt, int start) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < v.size(); i++) {
		arr[cnt] = v[i];
		dfs(cnt + 1, start + 1);
	}
}

void Solution() {
	sort(v.begin(), v.end());
	dfs(0, 0);
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