#include <iostream>

using namespace std;

int N, M;
bool arr[1000001];

void Input() {

	cin >> N >> M;
}

void Solution() {

	arr[0] = true;
	arr[1] = true;
	for (int i = 2; i <= M; i++) {

		if (!arr[i]) {
			if (i >= N) cout << i << '\n';

			int j = 2;
			while (i * j <= M) {
				arr[j++ * i] = true;
			}
		}
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