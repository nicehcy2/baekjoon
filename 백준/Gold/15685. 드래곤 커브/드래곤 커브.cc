#include <iostream>
#include <vector>

using namespace std;

int N, x, y, d, g;
bool arr[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<int> v;

int CheckSqaure() {
	int res = 0;

	for (int i = 0; i < 101 - 1; i++) {
		for (int j = 0; j < 101 - 1; j++) {
			if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1) {
				res++;
			}
		}
	}

	return res;
}

void dragonCurve() {
	int len = v.size();

	for (int i = len - 1; i >= 0; i--) {
		x += dx[(v[i] + 1) % 4];
		y += dy[(v[i] + 1) % 4];
		v.push_back(v[i] + 1);
		arr[x][y] = true;
	}
}

void Solution() {
	int res = CheckSqaure();

	cout << res << '\n';
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		v.clear();
		
		arr[x][y] = true;
		v.push_back(d);
		x += dx[d]; y += dy[d];
		arr[x][y] = true;
		
		for (int j = 0; j < g; j++) {
			dragonCurve();
		}
	}
}

int main() {
	Input();
	Solution();

	return 0;
}