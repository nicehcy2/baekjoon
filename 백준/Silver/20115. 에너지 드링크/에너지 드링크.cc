#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100001];

void Input() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void Solution() {

	sort(arr, arr + N);

	double ans = 0;

	for (int i = 0; i < N - 1; i++) {
		ans += arr[i];
	}
	ans /= 2;
	ans += arr[N - 1];

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