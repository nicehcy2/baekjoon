#include <iostream>
#include <algorithm>
#include <queue>

#define BUFSIZE 300001

using namespace std;

int n, k;
int m[BUFSIZE], v[BUFSIZE], c[BUFSIZE];
pair<int, int> valuableJewel[BUFSIZE];
priority_queue<int> pq;

void Input() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> m[i] >> v[i];
	}

	for (int i = 1; i <= k; i++) {
		cin >> c[i];
	}
}

void Solution() {
	long long sum = 0;
	int cnt = 1;

	for (int i = 1; i <= n; i++) {
		valuableJewel[i] = { m[i], v[i]};
	}
	sort(valuableJewel + 1, valuableJewel + n + 1);
	sort(c + 1, c + k + 1);

	for (int i = 1; i <= k; i++) {
		while (cnt <= n && valuableJewel[cnt].first <= c[i]) {
			pq.push(valuableJewel[cnt].second);
			cnt++;
		}

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}