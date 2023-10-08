#include <iostream>
#include <vector>;
#include <algorithm>

using namespace std;

int m, n, k, cnt = 0, area = 0;
vector<int> v;
bool arr[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void Input() {
	int x1, y1, x2, y2;

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int p = y1; p < y2; p++) {
			for (int q = x1; q < x2; q++) {
				arr[p][q] = true;
			}
		}
	}
}

void dfs(int y, int x) {
	area++;
	arr[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (!arr[ny][nx] && ny >= 0 && ny < m && nx >= 0 && nx < n) {
			dfs(ny, nx);
		}
	}
}

void Solution() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!arr[i][j]) {
				area = 0;
				cnt++;
				dfs(i, j);
				v.push_back(area);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << '\n';

	/*
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	*/
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}