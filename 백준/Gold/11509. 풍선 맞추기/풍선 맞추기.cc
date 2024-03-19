#include <iostream>

using namespace std;

int N, ans = 0, num;
int arr[1000001];

void Input() {

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> num;

		if (arr[num] != 0) {
			arr[num]--;

			if (num - 1 > 0) arr[num - 1]++;
		}
		else {
			ans++;

			if (num - 1 > 0) arr[num - 1]++;
		}
	}
}

void Solution() {

	cout << ans << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}