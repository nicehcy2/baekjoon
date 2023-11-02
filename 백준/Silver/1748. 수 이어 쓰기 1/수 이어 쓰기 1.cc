#include <iostream>
#include <cmath>

using namespace std;

int n;

void Input() {
	cin >> n;
}

void Solution() {
	int answer = 0, addend = 1;

	for (int i = 1; i < 10; i++) {
		if (pow(10, i) <= n) {
			answer += i * (pow(10, i) - pow(10, i - 1));
		}
		else {
			addend = i;
			break;
		}
	}
	
	int start = pow(10, addend - 1);
	for (int i = start; i <= n; i++) {
		answer += addend;
	}

	cout << answer << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}