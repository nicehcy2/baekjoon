#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long arr[100001];

void Input() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void Solution() {

	sort(arr, arr + N);

	long long max = 0;

	if (N % 2 == 0) {
		for (int i = 0; i < N / 2; i++) {
			long long sum = arr[i] + arr[N - 1 - i];

			if (sum > max) max = sum;
		}
	}
	else {
		for (int i = 0; i < N / 2; i++) {
			long long sum = arr[i] + arr[N - 2 - i];

			if (sum > max) max = sum;
		}

		if (arr[N - 1] > max) max = arr[N - 1];
	}

	cout << max << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}