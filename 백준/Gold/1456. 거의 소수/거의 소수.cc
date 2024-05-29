#include <iostream>
#include <cmath>

using namespace std;

long arr[10000001];
long A, B;

void Input() {

	cin >> A >> B;
}

void Solution() {

	int ans = 0;

	for (int i = 2; i < 10000001; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(10000001); i++) {
		if (arr[i] == 0) continue;

		for (int j = i + i; j <= 10000001; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 2; i < 10000001; i++) {
		if (arr[i] != 0) {

			long temp = i;

			while ((double)i <= (double)B / (double)temp) {
				if ((double)i >= (double)A / (double)temp) {
					ans++;
				}
				temp = temp * i;
			}
		}
	}

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