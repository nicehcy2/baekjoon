#include <iostream>

using namespace std;

int N, M;

void Input() {
	
	cin >> N >> M;
}

void Solution() {

	long long res = 1;

	for (int i = 0; i < M; i++) {
		res *= (N - i);
	}
	for (int i = 0; i < M; i++) {
		res /= (M - i);
	}

	cout << res << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}