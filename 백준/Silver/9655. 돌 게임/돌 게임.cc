#include <iostream>
#include <string>
#include <set>

#define INF 2100000000

using namespace std;

int n;

void InitAndInput() {
	cin >> n;
}

void Solution() {
	bool flag = true;

	while (n != 0) {
		if (n >= 3) {
			n -= 3;
		}
		else {
			n--;
		}

		if (flag) flag = false;
		else flag = true;
	}

	if (!flag) cout << "SK\n";
	else cout << "CY\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InitAndInput();
	Solution();

	return 0;
}