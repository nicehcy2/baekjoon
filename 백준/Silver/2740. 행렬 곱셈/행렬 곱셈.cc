#include <iostream>

using namespace std;

int n, m, k;
int A[101][101];
int B[101][101];
int C[101][101];

void Input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> B[i][j];
		}
	}
}

void Solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < m; l++) {
				C[i][j] += A[i][l] * B[l][j];
			}
			cout << C[i][j] << " ";
		}
		cout << "\n";
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