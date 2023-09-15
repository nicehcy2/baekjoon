#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

#define INF 2100000000

using namespace std;

int h, w, n, m;

void InitAndInput() {
	cin >> h >> w >> n >> m;
}

void Solution() {

	int a = ceil(h / (n + 1.0));
	int b = ceil(w / (m + 1.0));

	cout << a * b << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InitAndInput();
	Solution();

	return 0;
}