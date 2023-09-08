#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

#define mod 1000000007

using namespace std;

long long n;
map<long long, int> m;


void InitAndInput() {
	cin >> n;
}

long long fib(long long x) {
	if (m[x]) {
		return m[x];
	}

	long long result = 0;

	if (x % 2 == 0) {
		result = (fib(x / 2) * ((fib(x / 2 + 1) + fib(x / 2 - 1)) % mod)) % mod;
	}
	else {
		result = (((fib((x + 1) / 2) * fib((x + 1) / 2) % mod) + (fib((x - 1) / 2) * fib((x - 1) / 2) % mod)) % mod);
	}

	return m[x] = result % mod;
}

void Solution() {
	m[0] = 0;
	m[1] = 1;
	m[2] = 1;

	cout << fib(n) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InitAndInput();
	Solution();

	return 0;
}