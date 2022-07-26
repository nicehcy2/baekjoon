#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	int count[10001] = { 0, };

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		count[num]++;
	}

	for (int i = 0; i < 10001; ++i) {
		for (int j = 0; j < count[i]; ++j) {
			cout << i << '\n';
		}
	}

	return 0;
}
