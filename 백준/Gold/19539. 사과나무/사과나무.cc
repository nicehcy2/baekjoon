#include <iostream>

using namespace std;

int N, arrSum = 0, two = 0;
int arr[100002];

void Input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		arrSum += arr[i];
		
		two += arr[i] / 2;
	}
}

void Solution() {

	if (arrSum % 3 == 0) {
		
		if (two >= arrSum / 3) cout << "YES\n";
		else cout << "NO\n";
	}

	else cout << "NO\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}