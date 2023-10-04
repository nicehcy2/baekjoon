#include <iostream>

using namespace std;

int n, x, y, cnt = 0;
bool arr[101][101];

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		
		for (int a = y; a < y + 10; a++) {
			for (int b = x; b < x + 10; b++) {
				if (!arr[a][b]) arr[a][b] = 1;
				else cnt++;
			}
		}
	}
}

void Solution() {
	cout << n * 100 - cnt << '\n';
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}