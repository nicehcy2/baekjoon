#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

long long a, b, c;
map<long long, long long> m;

void InitAndInput() {
	cin >> a >> b >> c;
}

long long Solution(long long num) {
	if (num == 1) {
		return a % c;
	}

	long long mul = Solution(num / 2) % c;

	if (num % 2 == 0) {
		return mul * mul % c;
	}
	else {
		return (mul * mul % c * a % c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InitAndInput();
	cout << Solution(b) % c << '\n';

	return 0;
}