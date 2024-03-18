#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[100001];

void Input() {

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> arr[i].second >> arr[i].first;
	}
}

void Solution() {

	int cnt = 0, curEnd = 0;
	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {

		if (curEnd <= arr[i].second) {
			curEnd = arr[i].first;
			cnt++;
		}
	}

	cout << cnt << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}